/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_list_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:20:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/23 18:40:04 by lvirgini         ###   ########.fr       */
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
static char	*if_str_is_null2(char const *s1, char const *s2, size_t n)
{
	if (!s1 && s2)
		return (ft_strdup_max(s2, n));
	if (s1 && !s2)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strnjoin2(char const *s1, char const *s2, size_t n)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*dest;

	dest = if_str_is_null2(s1, s2, n);
	if (dest)
		return (dest);
	len = ft_strlen(s1) + n;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i] && j < len)
		dest[j++] = s2[i++];
	while (j < n)
		dest[j] = '\0';
	dest[j] = '\0';
	return (dest);
}

char	*ft_strnjoin2_free(char *s1, char const *s2, size_t n)
{
	char *dst;

	dst = ft_strnjoin2(s1, s2, n);
	if (s1)
		free(s1);
	s1 = NULL;
	return (dst);
}


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
		new[*i] = ft_strnjoin2_free(new[*i], old_arg + j,
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
