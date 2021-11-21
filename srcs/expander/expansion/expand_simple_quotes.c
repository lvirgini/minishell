/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_simple_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:52:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 20:12:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_expansion	*expand_simple_quote(char *s, char **env)
{
	t_expansion	*expansion;
	int			quotes_len;

	(void)env;
	printf("expand simple quotes : %s\n", s); //
	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	quotes_len = strlen_quote(s, 0, CHAR_SIMPLE_QUOTE);
	expansion->value = malloc_list(1);
	if (!expansion->value)
	{
		perror("malloc expand_simple_quotes()");
		free(expansion);
		return (NULL);
	}
	expansion->value[0] = ft_strdup_max(s + 1, quotes_len - 2);
	if (!expansion->value[0] && quotes_len - 2 > 0)
	{
		perror("malloc expand_simple_quotes()");
		free(expansion);
		return (NULL);
	}
	expansion->size_to_remove = quotes_len;
	return (expansion);
}
