/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_init_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:19:00 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/25 09:47:59 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_shell(char ***env)
{
	static char	*shell[3];

	shell[1] = S_SHELL;
	shell[2] = NULL;
	exec_export(shell, env);
}

static char	*new_nb(char *value)
{
	int		nb;
	char	*new_nb_value;

	nb = ft_atoi(value);
	new_nb_value = ft_itoa(nb + 1);
	return (new_nb_value);
}

void	export_shlvl(char ***env)
{
	char		*value;
	char		*new_value;
	static char	*shlvl[3];

	shlvl[2] = NULL;
	value = get_env_value(*env, S_SHLVL);
	new_value = new_nb(value);
	if (value == NULL || new_value == NULL)
	{
		shlvl[1] = S_SHLVL1;
		exec_export(shlvl, env);
		return ;
	}
	shlvl[1] = ft_strjoin(S_SHLVL, new_value);
	if (shlvl[1])
		exec_export(shlvl, env);
	free(new_value);
	if (shlvl[1])
		free(shlvl[1]);
}

void	export_oldpwd(char *old, char ***env)
{
	static char	*oldpwd[3];

	oldpwd[1] = ft_strjoin(S_OLDPWD, old);
	if (oldpwd[1] == NULL)
		return ;
	oldpwd[2] = NULL;
	exec_export(oldpwd, env);
	free(oldpwd[1]);
}

void	unset_oldpwd(char ***env)
{
	static char	*oldpwd[3];

	oldpwd[1] = OLDPWD;
	oldpwd[2] = NULL;
	exec_unset(oldpwd, env);
}
