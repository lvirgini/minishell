/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/17 15:36:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// redirection ambigue : si $TEST="plusieurs elements"

int	check_redir_expansion(char **expansion, char *filename)
{
	size_t	i;

	i = 0;
	while (expansion[i])
		i++;
	if (i > 1)
	{
		display_error(ERR_AMBIGUS, filename);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_redir	*expand_redirection(t_redir *redir, char **env)
{
	t_redir		*first_redir;
	char		**expansion;
	char		*filename;

	first_redir = redir;
	while (redir)
	{
		filename = redir->filename;
		if (need_expand_str(filename))
		{
			expansion = NULL;
			expansion = expand(filename, env);
			if (check_expansion(expansion) == FAILURE)
			{
				free_list_redir(first_redir);
				return (NULL);
			}
			free(filename);
			filename = *expansion;
			free(expansion);
		}
		redir = redir->next;
	}
	return (first_redir);
}