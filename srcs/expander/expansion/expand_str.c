/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:15:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 14:14:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** create all expansion for this string.
*/

t_expansion	*expand_str(char *str, char **env)
{
	size_t		i;
	t_expansion	*expansion;
	t_expansion	*first;

	i = 0;
	first = NULL;
	while (str[i])
	{
		if (is_expansion(str[i]))
		{
			expansion = get_expansion(str + i, env);
			if (!expansion)
			{
				free_list_expansion(first);
				return (NULL);
			}
			expansion->start_of_the_expand = i;
			i += expansion->size_to_remove;
			first = add_back_expansion(first, expansion);
		}
		else
			i++;
	}
	return (first);
}

