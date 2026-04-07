/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad <ahmad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:00:00 by ahmad            #+#    #+#             */
/*   Updated: 2026/04/07 12:00:00 by ahmad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THEME_H
# define THEME_H

# define PROMPT_COLORED "\033[1;38;5;39m🐦 \033[1;38;5;51mminishell\033[1;38;5;208m➜\033[0m "
# define COLOR_RESET "\033[0m"
# define COLOR_BLUE "\033[1;38;5;39m"
# define COLOR_CYAN "\033[1;38;5;51m"
# define COLOR_ORANGE "\033[1;38;5;208m"
# define COLOR_YELLOW "\033[1;38;5;226m"
# define COLOR_GREEN "\033[1;38;5;82m"
# define COLOR_RED "\033[1;38;5;196m"
# define COLOR_GRAY "\033[38;5;244m"
# define COLOR_MAGENTA "\033[1;38;5;201m"

void		print_banner(void);
const char	*get_colored_prompt(void);
void		print_error(const char *cmd, const char *msg);
void		print_success(const char *msg);
void		print_info(const char *msg);
void		print_warning(const char *msg);
void		help_builtin(void);

#endif
