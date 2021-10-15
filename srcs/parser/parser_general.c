/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:53:06 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/15 13:19:17 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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


//// si "ls -l" ou 'ls -l' meme 'ls ' "ls "considéré comme un ensemble  "ls -l"  'ls ' commande introuvable
get cmd : while token type == word or doublequote or simplequote
				first = cmd
				next == args
	
get type = last token in this cmd (ici pipe)



convert simplequote :
convert $variable
*/