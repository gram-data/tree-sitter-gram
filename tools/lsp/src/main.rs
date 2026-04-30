//! Gram LSP server (`gram-lsp`).

use clap::{Parser, Subcommand};

#[derive(Parser, Debug)]
#[command(name = "gram-lsp")]
#[command(about = "Language server for Gram notation (JSON-RPC over stdio)")]
#[command(version = env!("CARGO_PKG_VERSION"))]
struct Args {
    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand, Debug)]
enum Command {
    /// Run the LSP server over stdio (JSON-RPC).
    Stdio,
}

fn main() {
    let args = Args::parse();
    let rt = tokio::runtime::Builder::new_multi_thread()
        .enable_all()
        .build()
        .expect("runtime");
    match args.command {
        Command::Stdio => {
            if let Err(e) = rt.block_on(gram_lsp::run_stdio()) {
                eprintln!("gram-lsp: {e}");
                std::process::exit(1);
            }
        }
    }
}
