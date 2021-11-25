/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:09 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/25 09:26:26 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_error(char *arg, int error)
{
	ft_putstr_fd("unset: ", STDERR_FILENO);
	if (error == NOT_ID)
	{
		ft_putstr_fd("`", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(S_NOT_ID, STDERR_FILENO);
	} //set a 1 variable globale
}

void	exec_unset(char **arg, char ***env)
{
	// Recreer SHLVL a 1 si unset SHLVL
	int		a;
	int		len;
	int		i;
	char	**unset_env;

	a = 1;
	unset_env = *env;
	while (arg[a])
	{
		i = is_valid_key(arg[a]);
		if (i == 0 || ft_strchr(arg[a], '='))
			unset_error(arg[a], NOT_ID);
		else
		{
			i = get_env_index(unset_env, arg[a]);
			if (i != -1)
			{
				len = listlen(unset_env);
				free(unset_env[i]);
				list_nmove(unset_env + i, unset_env + i + 1, len - i);
				unset_env[len - 1] = NULL;
			}
		}
		a++;
	}
}
