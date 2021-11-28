/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:00:14 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 21:54:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_this_redir(t_redir *redir)
{
	if (redir)
	{
		if (redir->filename)
			free(redir->filename);
		free(redir);
	}
}

void	free_list_redir(t_redir *redir)
{
	t_redir	*next;

	while (redir)
	{
		next = redir->next;
		free_this_redir(redir);
		redir = next;
	}
}
