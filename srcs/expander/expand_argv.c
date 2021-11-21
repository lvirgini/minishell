/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:09:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 12:30:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** add expansion and keep argv already good 
*/
/*
char	**expand_argv(char **argv, char **env)
{
	size_t		i;
	char		**expansion;

	i = 0;
	while (argv[i])
	{
		if (need_expand_str(argv[i]))
		{
			expansion = NULL;
			expansion = expand_list(argv[i], env);
			argv = redesign_expansion_argv(argv, i, expansion);
			if (!argv)
				return (NULL);
		//	print_list(argv);
			free(expansion);
		}
		i++;
	}
	return (argv);
}
*/

char	**expand_argv(char **argv, char **env)
{
	char 	**new_argv;
	size_t	i;
	t_expansion *expansion;

	i = 0;
	while (argv[i])
	{
		if (need_expand(argv[i]))
		{
			expansion = expand_str(argv[i], env);
			if (!expansion)
				return (NULL);
			new_argv = redesign_argv(argv, expansion, &i);
			free_expansion(expansion);
			argv = new_argv;
			if (!argv)
				return (NULL);
		}
		else
			i++;
	}
	return (argv);
}

/// argv = t$TEST"a" NULL
//		l	$TEST "a"
//		l	s | -l	a
//			[l|s] [-l|a]


t_bool	add_argv_expansion(char **new, char *old_arg, t_expansion *expansion, size_t *i)
{
	char	**value;
	size_t	j;

	j = 0;
	while (expansion)
	{
		new[*i] = ft_strnjoin(new[*i], old_arg + j, expansion->start_of_the_expand - j);
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

char	**redesign_argv(char **old, t_expansion *expansion, size_t *index)
{
	char	**new;
	size_t	i;

	new = malloc_list(listlen(old) + count_expansion_split(expansion) + 1);
	if (!new)
		return (NULL);
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
}
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