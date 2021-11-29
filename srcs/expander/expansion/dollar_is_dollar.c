/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_is_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:25:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/28 15:03:16 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** complete expansion : on minishell it is solo "$".
*/

t_expansion	*dollar_is_dollar(void)
{
	t_expansion	*expansion;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	expansion->size_to_remove = 1;
	expansion->value = ft_split_set("$", STR_ESCAPE);
	if (expansion->value == NULL)
	{
		free(expansion);
		return (NULL);
	}
	return (expansion);
}
