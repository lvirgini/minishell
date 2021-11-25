/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:04:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 13:54:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ex error : 
**		si error syntax :  n'effectue aucune commande ! 
**			si un metacharactere puis un autre metacharactere.
**			<<<
**			bash: erreur de syntaxe près du symbole inattendu « newline »
**			<|<
**			bash: erreur de syntaxe près du symbole inattendu « | »  
**					------> $? = 2
*/

int	print_syntax_error(int err, char char_data, char *str_data)
{
	static char	*syntax[NB_ERR_SYNTAX] = {
		"syntax error near unexpected token",
		"syntax error quotes are not closed"};

	if (err == 0)
	{
		if (str_data)
			printf("minishell: %s « %s »\n", syntax[err], str_data);
		else if (char_data == '\0')
			printf("minishell: %s « newline »\n", syntax[err]);
		else
			printf("minishell: %s « %c »\n", syntax[err], char_data);
	}
	else
		printf("minishell: %s : %s\n", syntax[err], str_data);
	// SET ERRNO A 2
	// a imprimer sur STDERR
	return (-1);
}

/*
** SYNTAX ERROR from redirections : 
**
** if no token after redirection : it's the end of line
** if token after is another redirection or operator
*/

int	syntax_error_redirection(t_token *token)
{
	if (!token->next)
	{
		print_syntax_error(ERR_SYMBOL, '\0', NULL);
		return (SYNTAX_ERROR);
	}
	if (is_token_words(token->next->type) == false)
	{
		print_syntax_error(ERR_SYMBOL, 0, token->next->word);
		return (SYNTAX_ERROR);
	}
	return (SUCCESS);
}
