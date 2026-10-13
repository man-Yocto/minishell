# Minishell - 42 School Project

[![CI](https://github.com/man-Yocto/minishell/actions/workflows/ci.yml/badge.svg)](https://github.com/man-Yocto/minishell/actions/workflows/ci.yml)

A simple shell implementation in C that replicates core UNIX shell functionality. Built as part of the 42 school curriculum with a focus on systems programming concepts.

## Features

- ✅ Command execution with PATH resolution
- ✅ Pipes (`|`) and redirections (`<`, `>`, `>>`)
- ✅ Heredoc (`<<`) support
- ✅ Environment variable expansion (`$VAR`, `$?`, `$$`)
- ✅ Quote handling (single `'` and double `"`)
- ✅ Signal handling (SIGINT, SIGQUIT)
- ✅ Built-in commands: `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`
- ✅ SHLVL tracking and proper environment management

## Build & Run

```bash
make              # Build the project
./minishell       # Run the shell
make clean        # Remove object files
make fclean       # Remove everything
```

## Usage Examples

```bash
minishell> ls -la | grep .c
minishell> echo "Hello $USER" > output.txt
minishell> cat < input.txt | wc -l
minishell> cat << EOF
> Multi-line
> Heredoc input
> EOF
minishell> export MY_VAR="value"
minishell> echo $MY_VAR
value
```

## Architecture

The shell processes commands in this pipeline:
1. **Lexer** - Tokenizes input
2. **Parser** - Builds command structure
3. **Expander** - Expands variables
4. **Executor** - Executes commands with I/O handling

## Project Structure

```
minishell/
├── src/
│   ├── shell/      # Main REPL loop
│   ├── lexer/      # Tokenization
│   ├── parser/     # Command parsing
│   ├── expand/     # Variable expansion
│   ├── executor/   # Command execution & builtins
│   ├── env/        # Environment management
│   ├── signals/    # Signal handlers
│   ├── heredoc/    # Heredoc processing
│   └── clean/      # Memory cleanup
├── libft/          # Custom C library
├── include/        # Headers
└── Makefile
```

## Built-in Commands

| Command | Description |
|---------|-------------|
| `cd [path]` | Change directory |
| `echo [-n] [text]` | Print text |
| `pwd` | Print working directory |
| `export [VAR=value]` | Set environment variable |
| `unset [VAR]` | Remove environment variable |
| `env` | Display environment |
| `exit [code]` | Exit shell |

## Key technical challenges

- **Tokenizing like Bash** — splitting input into words and operators while respecting single and
  double quotes, where `'` disables expansion entirely and `"` still expands `$VAR`.
- **Variable expansion** — `$VAR`, `$?` and `$$`, applied after quote analysis but before word
  splitting, without breaking quoted strings.
- **Pipelines and redirections** — forking one process per command, wiring pipes and file
  descriptors with `dup2`, and closing every unused end so pipelines terminate.
- **Heredocs** — reading input until the delimiter before the pipeline starts, with expansion and
  correct `Ctrl-C` behaviour.
- **Signals** — different `SIGINT` / `SIGQUIT` handling at the prompt, during heredoc input, and in
  child processes, using `sigaction` and readline's `rl_on_new_line` / `rl_replace_line`.
- **Memory management** — freeing every token, command and environment copy on every path in a
  long-running interactive program.

## What I learned

<!-- TODO: write this section yourself -->

## Limitations

- No command history or tab completion
- No job control (`bg`, `fg`)
- No command substitution or glob patterns
- No logical operators (`&&`, `||`)
- No functions or conditionals

## References

- [42 School](https://www.42.fr/)
- [POSIX Shell](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

---
**Author:** Ahmad - 42 School Student
