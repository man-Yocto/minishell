# Minishell - 42 School Project

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
