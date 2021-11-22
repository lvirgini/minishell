/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:59:10 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 11:24:49 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_error(char *arg, int error)
{
	ft_putstr_fd("export: ", STDERR_FILENO);
	if (error == NOT_ID)
	{
		ft_putstr_fd("\'", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(S_NOT_ID, STDERR_FILENO);
	}
}

// void	print_export(char **env, int order)
// {
// 	int	i;
// 	(void)order;

// 	i = 0;
// 	while (env && env[i])
// 	{
		
// 	}
// }

void	exec_export(char **arg, char **env, t_builtin *builtin)
{
	(void)env;
	(void)builtin;
	(void)arg;
	// if (arg[])
}
