/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:29:35 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/10 14:54:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** get token pipe :
**
** for minishell basic only '|'
** for minishell bonus : '||', '|'
** in bash there is : '|', '||',  '|&',  
*/

int	get_token_pipe(t_token *token, char *line)
{
	token->word = ft_strdup_max(line, 1); // est ce qu'on a vraiment besoin de dup ca ?
	if (!token->word)
	{
		perror("malloc get_token_pipe()");
		return (FAILURE);
	}
	token->len = 1;
	token->type = PIPE;
	return (SUCCESS);
}