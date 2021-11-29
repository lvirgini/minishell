/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:04:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 13:31:03 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

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
		"syntax error near unexpected token «",
		"syntax error quotes are not closed «"};

	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(syntax[err], STDERR_FILENO);
	if (err == 0 && !str_data)
	{
		if (char_data == '\0')
			ft_putstr_fd("newline", STDERR_FILENO);
		else
			write(STDERR_FILENO, &char_data, 1);
	}
	else
		ft_putstr_fd(str_data, STDERR_FILENO);
	ft_putstr_fd("»\n", STDERR_FILENO);
	g_exit.status = 2;
	return (SYNTAX_ERROR);
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
