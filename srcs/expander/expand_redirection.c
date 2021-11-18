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
/*
static int	check_redir_expansion(char **expansion, char *filename)
{
	size_t	i;

	i = 0;
	while (expansion[i])
		i++;
	if (i > 1)
	{
		display_error(ERR_AMBIGUOUS, filename);
		return (FAILURE);
	}
	return (SUCCESS);
}
*/
/*
t_redir	*expand_redirection(t_redir *redir, char **env)
{
	t_redir		*first_redir;
	char		**expansion;

	first_redir = redir;
	while (redir)
	{
		if (need_expand_str(redir->filename))
		{
			expansion = NULL;
			expansion = expand(redir->filename, env);
			if (check_redir_expansion(expansion, redir->filename) == FAILURE)
			{
				free_list_redir(first_redir);
				return (NULL);
			}
			free(redir->filename);
			redir->filename = *expansion;
			free(expansion);
		}
		redir = redir->next;
	}
	return (first_redir);
}*/

int	expand_redirection(t_redir *redir, char **env)
{
	char		**expansion;

	expansion = NULL;
	expansion = expand(redir->filename, env);
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
