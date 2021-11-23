/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 19:51:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
// redirection ambigue : si $TEST="plusieurs elements"
// t_expansion list_toutes les expansion.
//
	si plusieurs char * dans une expansion : $TEST = "s -l" :
		: erreur ambigue
	si une seule char * $TEST="lsl" : fusion avec char *filename 


ex:   toto$USER"truc pouet" -> totominitruc pouet
ex:		toto$TEST		-> erreur ambigue car "totos" et "-l".

	pour redirection : 
					filename		expansion
					l$TEST"a"
					l[s] [-l]"a"		> ERR_AMBIGOUS : expansion > 1

					fiename			expansion
					l$USER"a b"
					l[mini]"a b "		$USER="mini" = 1 char * = OK
					lmini["a b"]		"a b"="a\ b" = 1 char * = OK
					lminia\ b		

	pour argv : 
					argv0			argv1		argv2
	si l$TEST"a" : 	l$TEST"a"		NULL
	expand $TEST	l[s] [-l]"a"	NULL
					ls				-l"a"		NULL
					ls				-la			NULL
*/
/*
expand_str	t_expand *expansion char *s;

while (s[i])
	if (s[i] == NEED_EXPAND)
		expansion = expand (s[i])
		add_back(expansion, expand (s[i]));
		if !t_expansion
			return NULL
		i++;


expand_list

{
	expansion = malloc_expansion
	while list
			expansion = expand_str;
			if (!expansion)
	}
		if listlen(expansion) > 1
			err ERR_AMBIGUOU
			return FAILURE
		fusion expansion;
*/

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
