/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:34:34 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/16 13:25:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		display_command_error(char	*cmd, int reason)
{
	static char *reason_str[] = {"Command not found\n"};

	ft_putstr(getenv("SHELL"));
	ft_putstr(": ");
	ft_putstr(cmd);
	ft_putstr(": ");
	ft_putstr(reason_str[reason]);
}