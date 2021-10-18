/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_t_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:54:42 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/18 21:52:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir *malloc_t_redir(t_token *token)
{
	t_redir *redirection;

	redirection = (t_redir *)malloc(sizeof(t_redir));
	if (!redirection)
	{
		perror("malloc add_t_redir()");
		return (NULL);
	}
	redirection->next = NULL;
	redirection->filename = ft_strdup(token->word);
	return (redirection);
}

void	add_back_t_redir(t_redir *redirection, t_redir *to_add)
{
	while (redirection->next)
		redirection = redirection->next;
	//redirection->next = add_t_redir(token);
	redirection->next = to_add;
}