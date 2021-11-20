/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:15:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 15:31:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_expansion	*expand_str(char *str, char **env)
{
	size_t		i;
	t_expansion	*expansion;
	t_expansion *first;
	
	first = NULL;
	i = 0;
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
			first = struct_add_front(first, expansion);
			i += expansion->size_to_remove;
			i++;
		}
		else
			i++;
	}
	return (NULL);
}
		/*if (str[i] == CHAR_DOLLAR)
			struct_add_back(expansion, expand_dollar(str + i, env));
		else if (*str == CHAR_DOUBLE_QUOTE)
			return (expand_double_quote(str));
		else if (*str == CHAR_SIMPE_QUOTE)
			return (expand_simple_quote(str));*/
	//	if (!str)
	//		return (NULL);