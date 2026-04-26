//! Zed extension host glue: starts `gram-lsp` from `PATH` or downloads a release asset.

use zed_extension_api::{
    self as zed,
    github_release_by_tag_name,
    set_language_server_installation_status,
    Architecture, Command, DownloadedFileType, Extension, LanguageServerId,
    LanguageServerInstallationStatus, Os, Result, Worktree, current_platform, download_file,
    make_file_executable,
};

const GRAM_REPO: &str = "gram-data/tree-sitter-gram";

struct GramExtension {
    /// Relative path (under the extension work dir) or absolute path from `which`.
    cached_binary: Option<String>,
}

impl GramExtension {
    fn rust_target_triple() -> Result<&'static str> {
        match current_platform() {
            (Os::Mac, Architecture::Aarch64) => Ok("aarch64-apple-darwin"),
            (Os::Mac, Architecture::X8664) => Ok("x86_64-apple-darwin"),
            (Os::Linux, Architecture::Aarch64) => Ok("aarch64-unknown-linux-gnu"),
            (Os::Linux, Architecture::X8664) => Ok("x86_64-unknown-linux-gnu"),
            (Os::Windows, Architecture::Aarch64) => Ok("aarch64-pc-windows-msvc"),
            (Os::Windows, Architecture::X8664) => Ok("x86_64-pc-windows-msvc"),
            (Os::Linux, Architecture::X86) | (Os::Windows, Architecture::X86) => Err(
                "gram-lsp: 32-bit platforms are not supported; install gram-lsp on PATH manually"
                    .into(),
            ),
            (Os::Mac, Architecture::X86) => Err(
                "gram-lsp: unexpected macOS x86 architecture; install gram-lsp on PATH manually"
                    .into(),
            ),
        }
    }

    fn gram_lsp_bin_name(os: Os) -> &'static str {
        match os {
            Os::Windows => "gram-lsp.exe",
            Os::Mac | Os::Linux => "gram-lsp",
        }
    }

    fn ensure_downloaded(
        &mut self,
        language_server_id: &LanguageServerId,
    ) -> Result<String> {
        let version = env!("GRAM_EXT_VERSION");
        let extract_dir = format!("gram-lsp-{version}");
        let (os, _) = current_platform();
        let bin_name = Self::gram_lsp_bin_name(os);
        let relative_binary = format!("{extract_dir}/{bin_name}");

        let triple = Self::rust_target_triple()?;
        let asset_name = format!("gram-lsp-{triple}.tar.gz");
        let tag = format!("v{version}");

        set_language_server_installation_status(
            language_server_id,
            &LanguageServerInstallationStatus::Downloading,
        );

        let release = match github_release_by_tag_name(GRAM_REPO, &tag) {
            Ok(r) => r,
            Err(e) => {
                let detail = format!(
                    "GitHub release {tag}: {e}. Install `gram-lsp` on PATH or publish release assets (see .github/workflows/gram-lsp-release-assets.yml)."
                );
                set_language_server_installation_status(
                    language_server_id,
                    &LanguageServerInstallationStatus::Failed(detail.clone()),
                );
                return Err(format!("gram-lsp: no GitHub release for {tag}: {e}"));
            }
        };

        let asset = match release.assets.iter().find(|a| a.name == asset_name) {
            Some(a) => a,
            None => {
                let msg = format!(
                    "gram-lsp: release {tag} has no asset {asset_name}. Build with the gram-lsp-release-assets workflow."
                );
                set_language_server_installation_status(
                    language_server_id,
                    &LanguageServerInstallationStatus::Failed(msg.clone()),
                );
                return Err(msg);
            }
        };

        if let Err(e) = download_file(
            &asset.download_url,
            &extract_dir,
            DownloadedFileType::GzipTar,
        ) {
            set_language_server_installation_status(
                language_server_id,
                &LanguageServerInstallationStatus::Failed(e.clone()),
            );
            return Err(format!("gram-lsp: download failed: {e}"));
        }

        if let Err(e) = make_file_executable(&relative_binary) {
            set_language_server_installation_status(
                language_server_id,
                &LanguageServerInstallationStatus::Failed(e.clone()),
            );
            return Err(format!("gram-lsp: chmod failed: {e}"));
        }

        set_language_server_installation_status(
            language_server_id,
            &LanguageServerInstallationStatus::None,
        );

        self.cached_binary = Some(relative_binary.clone());
        Ok(relative_binary)
    }
}

impl Extension for GramExtension {
    fn new() -> Self {
        Self {
            cached_binary: None,
        }
    }

    fn language_server_command(
        &mut self,
        language_server_id: &LanguageServerId,
        worktree: &Worktree,
    ) -> Result<Command> {
        if language_server_id.as_ref() != "gram-lsp" {
            return Err(format!(
                "unsupported language server id: {}",
                language_server_id.as_ref()
            ));
        }

        if let Some(path) = &self.cached_binary {
            return Ok(Command::new(path).arg("stdio"));
        }

        if let Some(path) = worktree.which("gram-lsp") {
            self.cached_binary = Some(path.clone());
            return Ok(Command::new(path).arg("stdio"));
        }

        let path = self.ensure_downloaded(language_server_id)?;
        Ok(Command::new(path).arg("stdio"))
    }
}

zed::register_extension!(GramExtension);
