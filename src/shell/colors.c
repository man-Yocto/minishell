/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad <ahmad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:00:00 by ahmad            #+#    #+#             */
/*   Updated: 2026/04/07 12:00:00 by ahmad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_error(const char *cmd, const char *msg)
{
	ft_putstr_fd(COLOR_RED "Error: " COLOR_RESET, 2);
	if (cmd)
	{
		ft_putstr_fd(COLOR_MAGENTA, 2);
		ft_putstr_fd((char *)cmd, 2);
		ft_putstr_fd(COLOR_RESET ": ", 2);
	}
	ft_putstr_fd(COLOR_YELLOW, 2);
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd(COLOR_RESET "\n", 2);
}

void	print_success(const char *msg)
{
	ft_putstr_fd(COLOR_GREEN "✓ " COLOR_RESET, 1);
	ft_putstr_fd((char *)msg, 1);
	ft_putstr_fd("\n", 1);
}

void	print_info(const char *msg)
{
	ft_putstr_fd(COLOR_CYAN "ℹ " COLOR_RESET, 1);
	ft_putstr_fd((char *)msg, 1);
	ft_putstr_fd("\n", 1);
}

void	print_warning(const char *msg)
{
	ft_putstr_fd(COLOR_ORANGE "⚠ " COLOR_RESET, 1);
	ft_putstr_fd((char *)msg, 1);
	ft_putstr_fd("\n", 1);
}
