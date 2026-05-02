use clap::{Parser, Subcommand};

mod check;
mod dispatch;
mod extension;
mod skill;
mod types;

#[derive(Parser)]
#[command(name = "gram", version = env!("CARGO_PKG_VERSION"), about = "Unified gram CLI")]
struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Subcommand)]
enum Commands {
    /// Validate .gram files for parse and semantic errors
    Check(check::CheckArgs),
    /// Manage gram extensions
    Extension(extension::ExtensionArgs),
    /// Manage gram agent skills
    Skill(skill::SkillArgs),
    /// Dispatch to an external gram-<name> binary on PATH
    #[command(external_subcommand)]
    External(Vec<String>),
}

fn main() {
    let cli = Cli::parse();
    let code = match cli.command {
        Commands::Check(args) => check::run(args),
        Commands::Extension(args) => extension::run(args),
        Commands::Skill(args) => skill::run(args),
        Commands::External(args) => dispatch::run(&args),
    };
    std::process::exit(code);
}
