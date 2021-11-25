/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_list_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:20:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 13:50:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	FUSION beween expansion and argv
**
** argv = t$TEST"a" NULL
**		l	$TEST "a"
**		l	s | -l	a
**			[l|s] [-l|a]
*/

static t_bool	update_fusion_argv(char **new, int *i, char **value)
{
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
	return (SUCCESS);
}

static t_bool	fusion_argv_expansion(char **new, char *old_arg,
	t_expansion *expansion, int *i)
{
	char	**value;
	size_t	j;

	j = 0;
	while (expansion)
	{
		new[*i] = ft_strnjoin_free(new[*i], old_arg + j,
				expansion->start_of_the_expand - j);
		if (!new[*i])
			return (FAILURE);
		value = expansion->value;
		if (update_fusion_argv(new, i, value) == FAILURE)
			return (FAILURE);
		j = expansion->start_of_the_expand + expansion->size_to_remove;
		expansion = expansion->next;
	}
	new[*i] = ft_strjoin_free(new[*i], old_arg + j);
	(*i)++;
	return (SUCCESS);
}

/*
** add all expansion and redesign new argv with split argument.
*/

t_bool	redesign_argv(char **new, char **old, t_expansion *expansion,
	int *index)
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
