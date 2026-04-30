# Feature Specification: Unified `gram` CLI with Extensions

**Feature Branch**: `007-unified-gram-cli`  
**Created**: 2026-04-30  
**Status**: Draft  
**Input**: User description: "a unified, extensible cli tool called `gram` which combines the best of gram-lint and gram-lsp as described in proposals/gram-cli-w-extentions.md"

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Check gram files for errors (Priority: P1)

A developer or CI pipeline wants to validate one or more `.gram` files for parse errors and diagnostics. They run `gram check` against a file, a glob, or a directory and receive human-readable feedback or structured JSON output.

**Why this priority**: This is the primary everyday use case that replaces both `gram-lint` and `gram-lsp check`. Without it, neither tool's users have a migration path.

**Independent Test**: Can be fully tested by running `gram check path/to/file.gram` and verifying that parse errors are reported correctly, independent of any extension or LSP functionality.

**Acceptance Scenarios**:

1. **Given** a `.gram` file with a syntax error, **When** a user runs `gram check file.gram`, **Then** the tool reports the error with file name and line number and exits with a non-zero status code.
2. **Given** a valid `.gram` file, **When** a user runs `gram check file.gram`, **Then** the tool exits with status 0 and produces no error output.
3. **Given** a directory of `.gram` files, **When** a user runs `gram check ./data/`, **Then** the tool traverses the directory and reports errors for all invalid files.
4. **Given** an inline expression, **When** a user runs `gram check -e "(a)-->(b)"`, **Then** the tool validates the expression and reports success or failure.
5. **Given** a piped input, **When** a user runs `echo "(a)" | gram check`, **Then** the tool reads from stdin and reports results.
6. **Given** any file with errors, **When** a user runs `gram check --json file.gram`, **Then** the tool produces machine-readable JSON diagnostics.
7. **Given** any file, **When** a user runs `gram check --tree file.gram`, **Then** the tool produces the parse tree as an s-expression.

---

### User Story 2 - Install and use extensions (Priority: P2)

A developer wants to add LSP support to their editor. They run `gram extension install lsp`, which downloads the `gram-lsp` binary, and then run `gram lsp stdio` to start the language server — without needing a Rust toolchain.

**Why this priority**: Extensions are the mechanism that makes the CLI composable and future-proof. The LSP use case is the first concrete extension and validates the entire installation path.

**Independent Test**: Can be fully tested by running `gram extension install lsp`, verifying the binary is installed to `~/.gram/bin/`, then running `gram lsp stdio` and confirming it starts the server.

**Acceptance Scenarios**:

1. **Given** a connected machine, **When** a user runs `gram extension install lsp`, **Then** the correct platform binary is downloaded to `~/.gram/bin/gram-lsp` without requiring a Rust toolchain.
2. **Given** a previously installed `lsp` extension, **When** a user runs `gram lsp stdio`, **Then** `gram` dispatches to the installed `gram-lsp` binary which starts the LSP server.
3. **Given** no internet connection, **When** a user runs `gram extension install lsp`, **Then** the tool reports a clear error and exits non-zero without corrupting state.
4. **Given** a previously installed extension, **When** a user runs `gram extension list`, **Then** the tool lists installed extensions and their versions.
5. **Given** an installed extension, **When** a user runs `gram extension remove lsp`, **Then** the binary is removed from `~/.gram/bin/`.

---

### User Story 3 - Third-party sub-command dispatch (Priority: P3)

A tool author publishes a binary named `gram-fmt` on `$PATH`. A user who has it installed simply runs `gram fmt`, and `gram` delegates to the external binary automatically — no registration required.

**Why this priority**: Sub-command dispatch enables an open ecosystem without central coordination. It is the fallback used by extensions and third parties alike.

**Independent Test**: Can be fully tested by placing a script named `gram-fmt` on `$PATH` and verifying that `gram fmt` executes it, passing arguments through correctly.

**Acceptance Scenarios**:

1. **Given** a binary named `gram-fmt` on `$PATH`, **When** a user runs `gram fmt file.gram`, **Then** `gram` execs `gram-fmt file.gram` and passes the exit code through.
2. **Given** no binary named `gram-unknown` on `$PATH`, **When** a user runs `gram unknown`, **Then** `gram` reports a helpful "unknown sub-command" error and exits non-zero.
3. **Given** a built-in sub-command (e.g., `check`), **When** a user also has `gram-check` on `$PATH`, **Then** the built-in takes priority over the external binary.

---

### User Story 4 - CI/CD pipeline integration (Priority: P2)

A team adds gram file linting to their CI pipeline. They install `gram` via a one-line curl command and use `gram check **/*.gram` to fail the build on syntax errors.

**Why this priority**: CI usage is a primary adoption driver. It must work without a Rust toolchain and with a pinnable version.

**Independent Test**: Can be fully tested by simulating a CI environment (fresh shell, no Rust) with the installer script, then running `gram check` against a known set of files and verifying exit codes.

**Acceptance Scenarios**:

1. **Given** a CI environment without Rust, **When** the team runs the installer script, **Then** `gram` is available on `$PATH` within seconds.
2. **Given** a glob pattern `**/*.gram`, **When** a user runs `gram check **/*.gram`, **Then** all matching files are checked and errors are reported per-file.
3. **Given** a pinned version in the install command, **When** the CI runs `gram extension install lsp@0.3.6`, **Then** exactly version `0.3.6` of the extension is installed.

---

### Edge Cases

- What happens when a `.gram` file contains valid syntax but semantic warnings? (Warnings should be reported but should not cause non-zero exit unless `--strict` is specified.)
- How does the tool handle a directory with no `.gram` files? (Should exit 0 with an informational message.)
- What happens when `~/.gram/bin/` is not on `$PATH`? (The installer or `gram` itself should warn the user to add it.)
- How does the tool handle conflicting extension versions? (Install should prompt the user or accept a `--force` flag.)
- What happens when stdin is used alongside file arguments? (Should be treated as an additional input, consistent with common CLI conventions.)

## Requirements *(mandatory)*

### Functional Requirements

**Built-in sub-commands**

- **FR-001**: `gram check` MUST accept one or more file paths, directory paths, and glob patterns as arguments.
- **FR-002**: `gram check` MUST accept an inline expression via a `-e` flag (e.g., `gram check -e "(a)-->(b)"`).
- **FR-003**: `gram check` MUST accept input from stdin when no file arguments are given.
- **FR-004**: `gram check` MUST traverse directories recursively and check all `.gram` files found.
- **FR-005**: `gram check` MUST support a `--json` flag that outputs diagnostics as machine-readable JSON.
- **FR-006**: `gram check` MUST support a `--tree` flag that outputs the parse tree as an s-expression.
- **FR-007**: `gram check` MUST exit with status code 0 when no errors are found and non-zero when errors exist.
- **FR-008**: `gram extension install <name>` MUST download a platform-specific pre-built binary from the extension's GitHub Releases and place it in `~/.gram/bin/`.
- **FR-009**: `gram extension list` MUST display currently installed extensions with their versions, and (with a flag or by default) list extensions available in the registry.
- **FR-010**: `gram extension remove <name>` MUST delete the extension binary from `~/.gram/bin/`.
- **FR-011**: `gram extension install <name>@<version>` MUST install a pinned version of an extension.

**Sub-command dispatch**

- **FR-012**: `gram` MUST attempt to exec a `gram-<subcommand>` binary on `$PATH` when a sub-command is not built-in.
- **FR-013**: Built-in sub-commands MUST take precedence over any external `gram-*` binary of the same name.
- **FR-014**: `gram` MUST forward all arguments and pass through the exit code when dispatching to an external binary.
- **FR-015**: `gram` MUST report a clear error message when an unknown sub-command is given and no matching `gram-*` binary exists on `$PATH`.

**Extension registry**

- **FR-016**: The extension registry MUST be a static manifest (TOML or similar) hosted in a public repository — no custom server required.
- **FR-017**: Each registry entry MUST include at minimum: extension name, description, source repository, and binary artifact naming convention.

### Key Entities *(include if feature involves data)*

- **Extension**: A named capability installable via `gram extension install`. Has a name, version, source repository, and one binary per supported platform.
- **Extension Registry**: A curated manifest listing known extensions. Fetched on demand by `gram extension list` and `gram extension install`.
- **Diagnostic**: A parse error or warning produced by `gram check`. Has a file path, line/column range, severity, and message.
- **Sub-command**: Either a built-in (`check`, `extension`) or an external binary on `$PATH` matching the pattern `gram-<name>`.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: A developer previously using `gram-lint` or `gram-lsp check` can migrate to `gram check` and achieve identical results using a single command.
- **SC-002**: A user with no Rust toolchain can install `gram` and the `lsp` extension and have a working LSP server in under 2 minutes from a fresh machine.
- **SC-003**: CI pipelines can lint an entire repository of `.gram` files and obtain per-file, machine-readable diagnostics with a single `gram check` invocation.
- **SC-004**: Third-party tools named `gram-*` are automatically available as `gram` sub-commands without any configuration or registration by the user.
- **SC-005**: A pinned extension version installed in CI produces identical behavior across runs, with no implicit upgrades.
- **SC-006**: Users of the standalone `gram-lint` binary can drop-in replace it with `gram check` without changing their scripts or aliases.

## Assumptions

- Extensions are distributed as pre-built binaries via GitHub Releases; source-only extensions are out of scope for the initial release.
- The extension installation directory is `~/.gram/bin/`. PATH management (adding this directory to the user's shell profile) is handled by the installer script or documented as a manual step.
- `gram check` replaces `gram-lint` for linting use cases; the standalone `gram-lint` binary will be deprecated but not immediately removed.
- Cargo feature flags for compile-time extension bundling (e.g., `cargo install gram --features lsp`) are a stretch goal and not required for the first release.
- The extension registry is a static file in the `gram-data` GitHub organization; a lockfile for reproducible environments is deferred to a future iteration.
- `gram check` uses "check" (aligned with `cargo check`) rather than "lint" to signal correctness checking over style enforcement.
