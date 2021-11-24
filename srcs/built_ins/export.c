/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:59:10 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/24 19:29:00 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_error(char *arg, int error)
{
	ft_putstr_fd("export: ", STDERR_FILENO);
	if (error == NOT_ID)
	{
		ft_putstr_fd("`", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(S_NOT_ID, STDERR_FILENO);
	}
}

void	export_oldpwd(char *old, char ***env)
{
	static char	*oldpwd[3];

	oldpwd[1] = ft_strjoin(OLDPWD, old);
	if (oldpwd[1] == NULL)
		return ;
	oldpwd[2] = NULL;
	exec_export(oldpwd, env);
	free(oldpwd[1]);
}

void	print_export(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		printf("%s\n", env[i]); //print key="value"
		i++;
	}
}

int	is_valid_key(char *str)
{
	int	i;

	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (i);
}

void	exec_export(char **arg, char ***env)
{
	int		a;
	int		index_key;

	a = 1;
	if (arg[a] == NULL)
		print_export(*env);
	while (arg[a])
	{
		index_key = is_valid_key(arg[a]);
		if (index_key == 0)
			export_error(arg[a], NOT_ID);
		else
		{
			index_key = get_env_index(*env, arg[a]);
			if (index_key != -1 && ft_strchr(arg[a], '='))
				edit_env(*env, index_key, arg[a]);
			else if (index_key == -1)
				add_new_env(env, arg[a]);
		}
		a++;
	}
}
