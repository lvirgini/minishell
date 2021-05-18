/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:34:34 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 10:33:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		display_command_error(t_env *env, char *cmd, int reason)
{
	static char *reason_str[] = {"Command not found\n"};

	ft_putstr(get_value_t_env(env, "SHELL"));
	ft_putstr(": ");
	ft_putstr(cmd);
	ft_putstr(": ");
	ft_putstr(reason_str[reason]);
}
