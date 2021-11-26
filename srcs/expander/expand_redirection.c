/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/26 15:58:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_redir_expansion(t_expansion *expansion, char *filename)
{
	int	null_expansion;

	null_expansion = 0;
	if (get_expand_removed_len(expansion) == ft_strlen(filename))
		null_expansion = 1;
	while (expansion)
	{
		if (listlen(expansion->value) > 1)
			return (FAILURE);
		if (expansion->value != NULL)
			null_expansion = 0;
		expansion = expansion->next;
	}
	if (null_expansion)
		return (FAILURE);
	return (SUCCESS);
}

/*
** change filename if need to expand it.
** if 
*/

int	expand_redirection(t_redir *redir, char **env)
{
	t_expansion	*expansion;

	if (need_expand(redir->filename))
	{
		expansion = expand_str(redir->filename, env);
		if (!expansion)
			return (FAILURE);
		if (check_redir_expansion(expansion, redir->filename) == FAILURE)
		{
			display_error(ERR_AMBIGUOUS, redir->filename);
			free_list_expansion(expansion);
			return (FAILURE);
		}
		redir->filename = fusion_str_expansion(redir->filename, expansion);
		free_list_expansion(expansion);
		if (!redir->filename)
			return (FAILURE);
	}
	return (SUCCESS);
}
