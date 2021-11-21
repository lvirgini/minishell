/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:09:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 20:21:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_unused_old_argv(t_cmd *cmd, int index_to_remove)
{
	free(cmd->argv[index_to_remove]);
	cmd->argv[index_to_remove] = NULL;
	free(cmd->argv);
}

/*
** add expansion and keep argv already good 
*/

void	get_new_argv_with_expansion(t_cmd *cmd, int *i, t_expansion *expansion)
{
	char		**new_argv;
	int			index_to_remove;

	new_argv = malloc_list((int)(listlen(cmd->argv)
				+ count_expansion_split(expansion)) + 1);
	if (new_argv)
	{
		index_to_remove = *i;
		if (redesign_argv(new_argv, cmd->argv, expansion, i) == FAILURE)
		{
			free_n_list(new_argv, *i);
			new_argv = NULL;
		}
		else
			free_unused_old_argv(cmd, index_to_remove);
	}
	else
		free_list(cmd->argv);
	cmd->argv = new_argv;
}

void	expand_argv(t_cmd *cmd, char **env)
{
	int			i;
	t_expansion	*expansion;

	i = 0;
	while (cmd->argv[i])
	{
		if (need_expand(cmd->argv[i]))
		{
			expansion = expand_str(cmd->argv[i], env);
			if (!expansion)
			{
				free_list(cmd->argv);
				cmd->argv = NULL;
				return ;
			}
			get_new_argv_with_expansion(cmd, &i, expansion);
			free_list_expansion(expansion);
			if (!cmd->argv)
				return ;
		}
		else
			i++;
	}
}
