//! `tower-lsp` server (stdio).

use std::collections::BTreeMap;
use std::path::{Path, PathBuf};
use std::sync::Arc;

use tokio::sync::RwLock;
use tower_lsp::jsonrpc::Result;
use tower_lsp::lsp_types::*;
use tower_lsp::{Client, LanguageServer, LspService, Server};

use crate::diagnostics;
use crate::symbols::SymbolIndex;
use crate::utf16;

#[derive(Clone, Debug)]
pub struct Backend {
    client: Client,
    /// Open and workspace-indexed documents (UTF-8); `BTreeMap` for stable definition search order.
    docs: Arc<RwLock<BTreeMap<Url, String>>>,
    workspace_roots: Arc<RwLock<Vec<PathBuf>>>,
}

impl Backend {
    pub fn new(client: Client) -> Self {
        Self {
            client,
            docs: Arc::new(RwLock::new(BTreeMap::new())),
            workspace_roots: Arc::new(RwLock::new(Vec::new())),
        }
    }

    async fn publish_diagnostics(&self, uri: Url) {
        let text = {
            let g = self.docs.read().await;
            g.get(&uri).cloned()
        };
        let Some(text) = text else { return };
        let (_, diags) = diagnostics::analyze_source(&text);
        let items: Vec<Diagnostic> = diags
            .iter()
            .map(|d| diagnostics::to_lsp_diagnostic(&text, d))
            .collect();
        self.client.publish_diagnostics(uri, items, None).await;
    }

    fn symbol_index(text: &str) -> SymbolIndex {
        let tree = crate::parse::parse(text);
        SymbolIndex::from_tree(&tree, text.as_bytes())
    }

    fn hover_text(text: &str, offset: usize) -> String {
        let tree = crate::parse::parse(text);
        let n = match tree.root_node().descendant_for_byte_range(offset, offset) {
            Some(n) => n,
            None => return String::new(),
        };
        let idx = SymbolIndex::from_tree(&tree, text.as_bytes());
        let mut parts = vec![format!("**{}**", n.kind())];
        if let Some(name) = idx.definition_at(offset) {
            parts.push(format!("(definition-introducing `{name}`)"));
        } else if let Some(name) = idx.reference_at(offset) {
            parts.push(format!("(reference `{name}`)"));
        }
        parts.join(" ")
    }

    async fn global_definition(&self, name: &str) -> Option<Location> {
        let g = self.docs.read().await;
        for (uri, text) in g.iter() {
            let idx = Self::symbol_index(text);
            if let Some((s, e)) = idx.first_definition(name) {
                let ((sl, sc), (el, ec)) = utf16::byte_range_to_lsp_range(text, s, e);
                return Some(Location {
                    uri: uri.clone(),
                    range: Range {
                        start: Position {
                            line: sl,
                            character: sc,
                        },
                        end: Position {
                            line: el,
                            character: ec,
                        },
                    },
                });
            }
        }
        None
    }

    async fn all_references(&self, name: &str) -> Vec<Location> {
        let g = self.docs.read().await;
        let mut out = Vec::new();
        for (uri, text) in g.iter() {
            let idx = Self::symbol_index(text);
            for (s, e) in idx.all_references(name) {
                let ((sl, sc), (el, ec)) = utf16::byte_range_to_lsp_range(text, s, e);
                out.push(Location {
                    uri: uri.clone(),
                    range: Range {
                        start: Position {
                            line: sl,
                            character: sc,
                        },
                        end: Position {
                            line: el,
                            character: ec,
                        },
                    },
                });
            }
        }
        out
    }
}

#[tower_lsp::async_trait]
impl LanguageServer for Backend {
    async fn initialize(&self, init: InitializeParams) -> Result<InitializeResult> {
        let mut roots = self.workspace_roots.write().await;
        roots.clear();
        if let Some(folders) = init.workspace_folders {
            for f in folders {
                if let Ok(path) = f.uri.to_file_path() {
                    roots.push(path);
                }
            }
        }
        if roots.is_empty() {
            if let Some(uri) = init.root_uri {
                if let Ok(path) = uri.to_file_path() {
                    if path.is_dir() {
                        roots.push(path);
                    }
                }
            }
        }
        drop(roots);
        self.index_workspace().await;

        Ok(InitializeResult {
            capabilities: ServerCapabilities {
                text_document_sync: Some(TextDocumentSyncCapability::Options(
                    TextDocumentSyncOptions {
                        open_close: Some(true),
                        change: Some(TextDocumentSyncKind::FULL),
                        ..Default::default()
                    },
                )),
                hover_provider: Some(HoverProviderCapability::Simple(true)),
                definition_provider: Some(OneOf::Left(true)),
                references_provider: Some(OneOf::Left(true)),
                completion_provider: Some(CompletionOptions {
                    resolve_provider: Some(false),
                    trigger_characters: Some(vec![":".into(), "[".into(), "(".into(), ",".into()]),
                    ..Default::default()
                }),
                ..Default::default()
            },
            server_info: Some(ServerInfo {
                name: "gram-lsp".into(),
                version: Some(env!("CARGO_PKG_VERSION").into()),
            }),
            offset_encoding: None,
        })
    }

    async fn initialized(&self, _: InitializedParams) {
        self.client
            .log_message(MessageType::INFO, "gram-lsp initialized")
            .await;
    }

    async fn shutdown(&self) -> Result<()> {
        Ok(())
    }

    async fn did_open(&self, p: DidOpenTextDocumentParams) {
        let uri = p.text_document.uri;
        let text = p.text_document.text;
        self.docs.write().await.insert(uri.clone(), text);
        self.publish_diagnostics(uri).await;
    }

    async fn did_change(&self, p: DidChangeTextDocumentParams) {
        let uri = p.text_document.uri;
        if let Some(ev) = p.content_changes.into_iter().next() {
            self.docs.write().await.insert(uri.clone(), ev.text);
        }
        self.publish_diagnostics(uri).await;
    }

    async fn did_close(&self, p: DidCloseTextDocumentParams) {
        self.docs.write().await.remove(&p.text_document.uri);
    }

    async fn hover(&self, p: HoverParams) -> Result<Option<Hover>> {
        let uri = p.text_document_position_params.text_document.uri;
        let pos = p.text_document_position_params.position;
        let text = {
            let g = self.docs.read().await;
            g.get(&uri).cloned()
        };
        let Some(text) = text else {
            return Ok(None);
        };
        let line_start = line_start_byte(&text, pos.line as usize);
        let mut col_utf16 = 0u32;
        let rest = &text[line_start..];
        for (i, ch) in rest.char_indices() {
            let end_utf16 = col_utf16 + ch.len_utf16() as u32;
            if pos.character < end_utf16 {
                let offset = line_start + i;
                let h = Self::hover_text(&text, offset);
                if h.is_empty() {
                    return Ok(None);
                }
                return Ok(Some(Hover {
                    contents: HoverContents::Markup(MarkupContent {
                        kind: MarkupKind::Markdown,
                        value: h,
                    }),
                    range: None,
                }));
            }
            col_utf16 = end_utf16;
        }
        Ok(None)
    }

    async fn goto_definition(
        &self,
        p: GotoDefinitionParams,
    ) -> Result<Option<GotoDefinitionResponse>> {
        let uri = p.text_document_position_params.text_document.uri;
        let pos = p.text_document_position_params.position;
        let text = {
            let g = self.docs.read().await;
            g.get(&uri).cloned()
        };
        let Some(text) = text else {
            return Ok(None);
        };
        let offset = position_to_byte(&text, pos);
        let idx = Self::symbol_index(&text);
        let name = idx.reference_at(offset).or_else(|| idx.definition_at(offset));
        let Some(name) = name else {
            return Ok(None);
        };
        let loc = self.global_definition(name).await;
        Ok(loc.map(GotoDefinitionResponse::Scalar))
    }

    async fn references(&self, p: ReferenceParams) -> Result<Option<Vec<Location>>> {
        let uri = p.text_document_position.text_document.uri;
        let pos = p.text_document_position.position;
        let text = {
            let g = self.docs.read().await;
            g.get(&uri).cloned()
        };
        let Some(text) = text else {
            return Ok(None);
        };
        let offset = position_to_byte(&text, pos);
        let idx = Self::symbol_index(&text);
        let name = idx
            .definition_at(offset)
            .or_else(|| idx.reference_at(offset));
        let Some(name) = name else {
            return Ok(None);
        };
        let mut locs = self.all_references(name).await;
        if p.context.include_declaration {
            if let Some((s, e)) = idx.first_definition(name) {
                let ((sl, sc), (el, ec)) = utf16::byte_range_to_lsp_range(&text, s, e);
                locs.push(Location {
                    uri: uri.clone(),
                    range: Range {
                        start: Position {
                            line: sl,
                            character: sc,
                        },
                        end: Position {
                            line: el,
                            character: ec,
                        },
                    },
                });
            }
        }
        Ok(Some(locs))
    }

    async fn completion(&self, p: CompletionParams) -> Result<Option<CompletionResponse>> {
        let uri = p.text_document_position.text_document.uri;
        let text = {
            let g = self.docs.read().await;
            g.get(&uri).cloned()
        };
        let Some(text) = text else {
            return Ok(None);
        };
        let idx = Self::symbol_index(&text);
        let mut items: Vec<CompletionItem> = idx
            .defs
            .iter()
            .map(|(name, _, _)| CompletionItem {
                label: name.clone(),
                kind: Some(CompletionItemKind::VARIABLE),
                ..Default::default()
            })
            .collect();
        items.sort_by(|a, b| a.label.cmp(&b.label));
        items.dedup_by(|a, b| a.label == b.label);
        Ok(Some(CompletionResponse::Array(items)))
    }
}

impl Backend {
    async fn index_workspace(&self) {
        let roots = self.workspace_roots.read().await.clone();
        let mut map = self.docs.write().await;
        for root in roots {
            if let Ok(entries) = scan_gram_files(&root) {
                for (path, content) in entries {
                    if let Ok(url) = Url::from_file_path(&path) {
                        map.entry(url).or_insert(content);
                    }
                }
            }
        }
    }
}

fn scan_gram_files(root: &Path) -> std::io::Result<Vec<(PathBuf, String)>> {
    let mut out = Vec::new();
    scan_dir(root, &mut out)?;
    Ok(out)
}

fn scan_dir(dir: &Path, out: &mut Vec<(PathBuf, String)>) -> std::io::Result<()> {
    if !dir.is_dir() {
        return Ok(());
    }
    for entry in std::fs::read_dir(dir)? {
        let entry = entry?;
        let p = entry.path();
        if p.is_dir() {
            scan_dir(&p, out)?;
        } else if p.extension().and_then(|s| s.to_str()) == Some("gram") {
            if let Ok(s) = std::fs::read_to_string(&p) {
                out.push((p, s));
            }
        }
    }
    Ok(())
}

fn line_start_byte(source: &str, line: usize) -> usize {
    let mut l = 0usize;
    for (i, ch) in source.char_indices() {
        if l == line {
            return i;
        }
        if ch == '\n' {
            l += 1;
        }
    }
    source.len()
}

fn position_to_byte(source: &str, pos: Position) -> usize {
    let line_start = line_start_byte(source, pos.line as usize);
    let rest = &source[line_start..];
    let mut utf16 = 0u32;
    for (i, ch) in rest.char_indices() {
        let end_utf16 = utf16 + ch.len_utf16() as u32;
        if pos.character < end_utf16 {
            return line_start + i;
        }
        utf16 = end_utf16;
    }
    line_start + rest.len()
}

pub async fn run_stdio() -> std::result::Result<(), Box<dyn std::error::Error + Send + Sync>> {
    let stdin = tokio::io::stdin();
    let stdout = tokio::io::stdout();
    let (service, socket) = LspService::new(Backend::new);
    Server::new(stdin, stdout, socket).serve(service).await;
    Ok(())
}
