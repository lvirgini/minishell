/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:09:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 19:20:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/// argv = t$TEST"a" NULL
//		l	$TEST "a"
//		l	s | -l	a
//			[l|s] [-l|a]


static t_bool	fusion_argv_expansion(char **new, char *old_arg, t_expansion *expansion,
	int *i)
{
	char	**value;
	int		j;

	j = 0;
	while (expansion)
	{
		new[*i] = ft_strnjoin_free(new[*i], old_arg + j, expansion->start_of_the_expand - j);
		if (!new[*i])
			return (FAILURE);
		value = expansion->value;
		while (value && *value)
		{
			new[*i] = ft_strjoin_free(new[*i], *value);
			if (!new[*i])
				return (FAILURE);
			if (++value && *value)
			{
				(*i)++;
				new[*i] = NULL;
			}
		}
		j = expansion->start_of_the_expand + expansion->size_to_remove;
		expansion = expansion->next;
	}
	(*i)++;
	return (SUCCESS);
}

/*
** add all expansion and redesign new argv with split argument.
*/

static t_bool	redesign_argv(char **new, char **old, t_expansion *expansion, int *index)
{
	int	i;

	list_nmove(new, old, *index);
	i = *index;
	new[i] = NULL;
	if (fusion_argv_expansion(new, old[*index], expansion, &i) == FAILURE)
		return (FAILURE);
	new[i] = NULL;
	list_move(new + i, old + *index + 1);
	*index = i;
	return (SUCCESS);
}

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

	new_argv = malloc_list((int)(listlen(cmd->argv) + count_expansion_split(expansion)) + 1);
	printf("%d\n",(int)(listlen(cmd->argv) + count_expansion_split(expansion)) + 1);
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
	int		i;
	t_expansion *expansion;
	
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

/*OLD
char	**redesign_argv(char **old, t_expansion *expansion, size_t *index)
{
	char	**new;
	size_t	i;

	new = malloc_list(listlen(old) + count_expansion_split(expansion) + 1);
	if (!new)
	{
		free_list(old);
		return (NULL);
	}
	list_nmove(new, old, *index);
	i = *index;
	new[i] = NULL;
	if (add_argv_expansion(new, old[*index], expansion, &i) == FAILURE)
	{
		free_list(new);
		free_list(old);
		return (NULL);
	}
	list_move(new + i, old + *index + 1);
	if (*index != 0)
		free(old[*index]);
	free(old);
	*index = i;
	return (new);
}*/
/*
static char	**redesign_expansion_argv(char **old_argv, int index,
			char **expansion)
{
	size_t	old_len;
	size_t	expand_len;
	char	**new_argv;

	old_len = listlen(old_argv);
	expand_len = listlen(expansion);
	new_argv = malloc_list(old_len + expand_len);
	if (!new_argv)
		return (NULL);
	list_nmove(new_argv, old_argv, index);
	list_move(new_argv + index, expansion);
	list_move(new_argv + index + expand_len, old_argv + index + 1);
	new_argv[old_len + expand_len - 1] = NULL;
	free(old_argv[index]);
	free(old_argv);
	return (new_argv);
}*/