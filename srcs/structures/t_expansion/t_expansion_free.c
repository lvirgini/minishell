/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_expansion_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:30:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 10:20:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_expansion(t_expansion	*expansion)
{
	if (expansion)
	{
		if (expansion->value)
			free(expansion->value);
		free(expansion);
	}
}

void	free_list_expansion(t_expansion *expansion)
{
	t_expansion	*next;

	if (expansion)
	{
		while (expansion)
		{
			next = expansion->next;
			free_expansion(expansion);
			expansion = next;
		}
	}
}
