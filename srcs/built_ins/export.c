/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:59:10 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/25 18:04:08 by eassouli         ###   ########.fr       */
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
	set_exit_status(1);
}

char	**sort_export(char **env)
{
	int		i;
	int		j;
	char	*tmp_key;
	char	**sort_env;

	i = 0;
	sort_env = list_dup(env);
	if (sort_env == NULL)
		return (NULL);
	while (sort_env[i])
	{
		j = i;
		while (j > 0 && ft_strcmp(sort_env[j], sort_env[j - 1]) < 0)
		{
			tmp_key = sort_env[j - 1];
			sort_env[j - 1] = sort_env[j];
			sort_env[j] = tmp_key;
			j--;
		}
		i++;
	}
	return (sort_env);
}

void	print_export(char **env)
{
	int		i;
	int		len;
	char	**sort_env;

	i = 0;
	sort_env = sort_export(env);
	while (sort_env && sort_env[i])
	{
		len = ft_strlen_set(sort_env[i], "=");
		write(1, sort_env[i], len);
		if (*(sort_env[i] + len) == '=')
			printf("=\"%s\"\n", sort_env[i] + len + 1);
		else
			printf("\n");
		i++;
	}
	if (sort_env)
		free_list(sort_env);
	sort_env = NULL;
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
	set_exit_status(0);
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
