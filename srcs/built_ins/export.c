/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:59:10 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/23 18:55:16 by eassouli         ###   ########.fr       */
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

// void	export_shlvl(char **env, t_builtin *builtin) //si introuvable set a 0 sinon +1
// {
// 	int		i;
// 	char	shlvl;

// 	i = 0;
// 	shlvl = get_env_value(env, "SHLVL");
// 	if (shlvl == NULL)
// 		exec_export(&S_SHLVL0, env);
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

static int	edit_env(char **env, int index, char *to_edit)
{
	free(env[index]);
	env[index] = to_edit;
	return (SUCCESS);
}

static char	**add_new_env(char **old, char *to_add)
{
	char	**new_list_env;
	int		env_size;

	env_size = listlen(old) + 1;
	new_list_env = malloc_list(env_size);
	if (!new_list_env)
	{
		free_list(old);
		return (NULL);
		// si malloc fail retourner l'ancien env ou tout quitter ?
	}
	list_nmove(new_list_env, old, env_size); //
	new_list_env[env_size - 1] = to_add;
	new_list_env[env_size] = NULL;
	free(old);
	return (new_list_env);
}

void	exec_export(char **arg, char **env) //faire SHLVL incrementer a chaque fois qu'on rentre dans un shell (des le debut) ou reset a 0 si introuvable
{
	// verifier premier char seulement aA_
	// verifier rester cle seulement aA_1
	int		i;
	int		index_key;
	int		size;
	char	*key;

	i = 1;
	key = NULL;
	if (arg[i] == NULL)
		print_export(env);
	// else if (ft_strchr(arg[0], S_CD) == 0)
	// else if (ft_strchr(arg[0], S_SHLVL0) == 0)
	while (arg[i])
	{
		size = is_valid_key(arg[i]);
		if (!size)
			export_error(arg[i], NOT_ID);
		else
		{
			index_key = get_env_index(env, arg[i]);
			if (index_key != -1 && arg[i] + size)
				edit_env(env, index_key, arg[i]);
			else if (index_key == -1)
				env = add_new_env(env, arg[i]);
		}
		i++;
	}
}
