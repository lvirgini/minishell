/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_expansion_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:12:49 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 10:14:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_expansion	*malloc_expansion(void)
{
	t_expansion	*expansion;

	expansion = (t_expansion *)malloc(sizeof(t_expansion));
	if (!expansion)
	{
		perror("malloc_expansion()");
		return (NULL);
	}
	ft_memset(expansion, 0, sizeof(t_expansion));
	return (expansion);
}

t_expansion	*malloc_expansion_and_value(int	size)
{
	t_expansion	*expansion;

	expansion = malloc_expansion();
	if (expansion)
	{
		expansion->value = malloc_list(size);
		if (!expansion->value)
		{
			perror("malloc in malloc_expansion_and_value()");
			free(expansion);
			expansion = NULL;
		}
	}
	return (expansion);
}
