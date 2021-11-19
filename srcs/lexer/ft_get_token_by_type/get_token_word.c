/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:17:03 by mini              #+#    #+#             */
/*   Updated: 2021/11/18 16:05:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** get token WORD : 
**		while is not a space or metacharacter or space.
*/

int	get_token_word(t_token *token, char *line)
{
	size_t	len;

	len = 0;
	while (line[len] && !is_metacharacter(line[len]) && !ft_isspace(line[len]))
		len++;
	token->word = ft_strdup_max(line, len);
	if (!token->word)
	{
		perror("malloc get_token_word()");
		return (FAILURE);
	}
	token->type = WORD;
	token->len = len;
	return (SUCCESS);
}
