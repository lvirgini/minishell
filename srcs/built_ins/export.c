/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:59:10 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 14:21:54 by eassouli         ###   ########.fr       */
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

// void	export_shlvl(char **env, t_builtin *builtin)
// {
// 	int		i;
// 	char	shlvl;

// 	i = 0;
// 	shlvl = get_env_value(env, "SHLVL");
// 	if (env == NULL)
// 		exec_export(&SHLVL, env, builtin);
// 	else
// 	{
		
// 	}
// }

void	print_export(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

void	exec_export(char **arg, char **env, t_builtin *builtin) //faire SHLVL incrementer a chaque fois qu'on rentre dans un shell (des le debut) ou reset a 0 si introuvable
{
	// int	i;
	// (void)builtin;

	// i = 0; // verifier premier char
	// if (arg[1] == NULL)
	// 	print_export(env);
	// else
	// {
	// 	while ()
	// 	{

	// 	}
	// }
}
