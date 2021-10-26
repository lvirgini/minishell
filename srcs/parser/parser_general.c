/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:53:06 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 15:47:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** PARSING : 
**
** 	create list_cmd
** 	there is no notion of priority for Minishell :
**	create the commands obtained by the token
**	syntax errors are checked at each token parsing
**	once all the tokens are parsed the list is complete
*/

t_cmd	**parser_minishell(t_token **token)
{
	t_cmd	**list_cmd;
	t_cmd	*new_cmd;

	if (!token)
		return (NULL);
	list_cmd = malloc_list_cmd();
	if (!list_cmd)
		return (NULL);
	while (*token)
	{
		new_cmd = get_next_cmd(token);
		if (!new_cmd)
		{
			free_list_cmd(list_cmd);
			return (NULL);
		}
		struct_list_add_back(list_cmd, new_cmd);
	}
	return (list_cmd);
}
