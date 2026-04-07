/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad <ahmad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:00:00 by ahmad            #+#    #+#             */
/*   Updated: 2026/04/07 12:00:00 by ahmad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	help_builtin(void)
{
	printf("\n");
	printf(COLOR_BLUE "╔════════════════════════════════════════════════════╗\n" COLOR_RESET);
	printf(COLOR_BLUE "║        " COLOR_CYAN "MINISHELL - Available Commands" COLOR_BLUE "         ║\n" COLOR_RESET);
	printf(COLOR_BLUE "╚════════════════════════════════════════════════════╝\n" COLOR_RESET);
	printf("\n");
	
	printf(COLOR_GREEN "  cd " COLOR_RESET "[" COLOR_YELLOW "path" COLOR_RESET "]\n");
	printf("    Change directory. Use " COLOR_YELLOW "'cd -'" COLOR_RESET " to go to previous directory.\n");
	printf("    " COLOR_GRAY "Example: cd /tmp, cd .., cd ~\n" COLOR_RESET "\n");

	printf(COLOR_GREEN "  echo " COLOR_RESET "[" COLOR_YELLOW "-n" COLOR_RESET "] [" COLOR_YELLOW "text" COLOR_RESET "]\n");
	printf("    Print text to output. Use " COLOR_YELLOW "'-n'" COLOR_RESET " to suppress newline.\n");
	printf("    " COLOR_GRAY "Example: echo \"Hello World\", echo -n \"No newline\"\n" COLOR_RESET "\n");

	printf(COLOR_GREEN "  pwd\n" COLOR_RESET);
	printf("    Print the current working directory.\n");
	printf("    " COLOR_GRAY "Example: pwd\n" COLOR_RESET "\n");

	printf(COLOR_GREEN "  export " COLOR_RESET "[" COLOR_YELLOW "VAR" COLOR_RESET "=" COLOR_YELLOW "value" COLOR_RESET "]\n");
	printf("    Set or display environment variables.\n");
	printf("    " COLOR_GRAY "Example: export MY_VAR=value, export MY_VAR\n" COLOR_RESET "\n");

	printf(COLOR_GREEN "  unset " COLOR_RESET "[" COLOR_YELLOW "VAR" COLOR_RESET "]\n");
	printf("    Remove environment variables.\n");
	printf("    " COLOR_GRAY "Example: unset MY_VAR\n" COLOR_RESET "\n");

	printf(COLOR_GREEN "  env\n" COLOR_RESET);
	printf("    Display all environment variables.\n");
	printf("    " COLOR_GRAY "Example: env, env | grep HOME\n" COLOR_RESET "\n");

	printf(COLOR_GREEN "  exit " COLOR_RESET "[" COLOR_YELLOW "code" COLOR_RESET "]\n");
	printf("    Exit the shell with an optional exit code.\n");
	printf("    " COLOR_GRAY "Example: exit, exit 42\n" COLOR_RESET "\n");

	printf(COLOR_BLUE "╔════════════════════════════════════════════════════╗\n" COLOR_RESET);
	printf(COLOR_BLUE "║           " COLOR_CYAN "Shell Features & Operators" COLOR_BLUE "            ║\n" COLOR_RESET);
	printf(COLOR_BLUE "╚════════════════════════════════════════════════════╝\n" COLOR_RESET);
	printf("\n");

	printf(COLOR_ORANGE "  Pipes " COLOR_RESET "|\n");
	printf("    Chain commands together. Output of left becomes input of right.\n");
	printf("    " COLOR_GRAY "Example: cat file.txt | grep pattern | wc -l\n" COLOR_RESET "\n");

	printf(COLOR_ORANGE "  Output Redirection " COLOR_RESET ">\n");
	printf("    Redirect output to a file (overwrite).\n");
	printf("    " COLOR_GRAY "Example: echo \"text\" > file.txt\n" COLOR_RESET "\n");

	printf(COLOR_ORANGE "  Append Redirection " COLOR_RESET ">>\n");
	printf("    Redirect output to a file (append).\n");
	printf("    " COLOR_GRAY "Example: echo \"text\" >> file.txt\n" COLOR_RESET "\n");

	printf(COLOR_ORANGE "  Input Redirection " COLOR_RESET "<\n");
	printf("    Redirect input from a file.\n");
	printf("    " COLOR_GRAY "Example: cat < file.txt\n" COLOR_RESET "\n");

	printf(COLOR_ORANGE "  Heredoc " COLOR_RESET "<<\n");
	printf("    Read multi-line input until delimiter.\n");
	printf("    " COLOR_GRAY "Example: cat << EOF\\n...\\nEOF\n" COLOR_RESET "\n");

	printf(COLOR_BLUE "╔════════════════════════════════════════════════════╗\n" COLOR_RESET);
	printf(COLOR_BLUE "║              " COLOR_CYAN "Special Variables" COLOR_BLUE "              ║\n" COLOR_RESET);
	printf(COLOR_BLUE "╚════════════════════════════════════════════════════╝\n" COLOR_RESET);
	printf("\n");

	printf(COLOR_MAGENTA "  $VAR\n" COLOR_RESET "    Expands to the value of the environment variable.\n");
	printf("    " COLOR_GRAY "Example: echo $HOME, echo $USER\n" COLOR_RESET "\n");

	printf(COLOR_MAGENTA "  $?\n" COLOR_RESET "    The exit status of the last executed command.\n");
	printf("    " COLOR_GRAY "Example: echo $?\n" COLOR_RESET "\n");

	printf(COLOR_MAGENTA "  $$\n" COLOR_RESET "    The process ID of the current shell.\n");
	printf("    " COLOR_GRAY "Example: echo $$\n" COLOR_RESET "\n");

	printf(COLOR_MAGENTA "  $0\n" COLOR_RESET "    The name/path of the shell.\n");
	printf("    " COLOR_GRAY "Example: echo $0\n" COLOR_RESET "\n");

	printf(COLOR_BLUE "╔════════════════════════════════════════════════════╗\n" COLOR_RESET);
	printf(COLOR_BLUE "║               " COLOR_CYAN "Quoting & Escaping" COLOR_BLUE "              ║\n" COLOR_RESET);
	printf(COLOR_BLUE "╚════════════════════════════════════════════════════╝\n" COLOR_RESET);
	printf("\n");

	printf(COLOR_CYAN "  'single quotes'\n" COLOR_RESET);
	printf("    Preserves literal value of all characters.\n");
	printf("    " COLOR_GRAY "Example: echo '$VAR' → $VAR (no expansion)\n" COLOR_RESET "\n");

	printf(COLOR_CYAN "  \"double quotes\"\n" COLOR_RESET);
	printf("    Allows variable expansion and escape sequences.\n");
	printf("    " COLOR_GRAY "Example: echo \"$VAR\" → (variable expanded)\n" COLOR_RESET "\n");

	printf(COLOR_CYAN "  \\backslash\n" COLOR_RESET);
	printf("    Escapes special characters.\n");
	printf("    " COLOR_GRAY "Example: echo \\$VAR → $VAR (no expansion)\n" COLOR_RESET "\n");

	printf("\n");
}
