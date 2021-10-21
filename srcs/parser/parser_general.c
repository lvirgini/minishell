/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:53:06 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/20 16:45:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** PARSING : 
*/

// creer la liste de cmd. 
// creer chaque cmd par rapport au token. ( pour minishell pas de notion de priorité
// du coup c'est linéaire mais sinon il faudrait eventuellement faire des multi_cmd
// et les organiser selon leur priorité.

t_cmd	**parser_minishell(t_env **env, t_token **token)
{
	(void)env;
	t_cmd **list_cmd;

	list_cmd = malloc_list_cmd();
	if (!list_cmd)
		return (NULL);
	*list_cmd = get_next_cmd(NULL, token);
	// tant que cmd existe on boucle avec list_cmd->next
	
	
	
	return (list_cmd);
}



/*
parsing 

while (token)
{
	t_cmd **cmd;
	t_cmd *current;

	*cmd = get_first_cmd(token)
	if cmd
		return NULL
	while (token)
	{
		current->next = get_next_cmd(token)
		current = current->next
		if (current)
			return NULL
	}
}


get_next_cmd()
{
	t_cmd
	{
		while is always one cmd
		{
			get_attribut_for_cmd(token->type)(token, cmd)
		}
	}

ft_get_attribut_for_cmd[]
	get_output
	get_input
	get_cmd
	get_argument
	get_type (pipe ? etc..)
}


get output : token actual == > 
			token after == word or doublequote or simplequote
						= char *output

get input : token actual == <
			token after == word or doublequote or simplequote
						= char *input

get	heredoc	token actual == <<
			token after == word or doublequote or simplequote
						= limiter
					
get append	token actual == >>
			token after == word or doublequote or simplequote

get pipe :	create pipe, si input ou output ou heredock ou append : ecrase le pipe
			 need cmd before ans cmd after

//// si "ls -l" ou 'ls -l' meme 'ls ' "ls "considéré comme un ensemble  "ls -l"  'ls ' commande introuvable
get cmd : while token type == word or doublequote or simplequote
				first = cmd
				next == args
	
get type = last token in this cmd (ici pipe)



convert simplequote :
convert $variable
*/