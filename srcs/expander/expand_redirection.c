/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/18 16:54:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// redirection ambigue : si $TEST="plusieurs elements"

int	expand_redirection(t_redir *redir, char **env)
{
	char		**expansion;

	expansion = NULL;
	expansion = expand_str(redir->filename, env);
	if (listlen(expansion) != 1)
	{
		display_error(ERR_AMBIGUOUS, redir->filename);
		free_list(expansion);
		return (FAILURE);
	}
	free(redir->filename);
	redir->filename = *expansion;
	free(expansion);
	return (SUCCESS);
}
