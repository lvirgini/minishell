/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_special_param.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:32:11 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 15:47:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** SPECIAL PARAM = $ with others : 
**      $*  $@  $#  $?  $-  $$  $!  $0 $"isalnum"
**
**  for minishell : only those two :
**      $? = last exit status of last cmd
**      $VARIABLE = get value of VARIABLE
*/
/*
int	get_token_special_param(t_token *token, char *line)
{
	size_t	len;

	len = 1;
	if ((line[len]) == '?')
	{
		token->type = EXIT_STATUS;
		len++;
	}	
	else if (ft_isalnum(line[len]))
	{
		token->type = VARIABLE;
		len++;
		// check si c'est bien nimporte quel lettre/nombre
		while (ft_isalnum(line[len])) 
			len++;
	}
	else
		return (FAILURE); // ERROR SYNTAX
	token->word = ft_strdup_max(line + 1, len - 1);
	if (!token->word)
	{
		perror("malloc get_token_special_param()");
		return (FAILURE);
	}	
	token->len = len;
	return (SUCCESS);
}
*/