/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:04:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 22:14:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Syntax Error:
**	if there is a syntax error, the shell stops and return to readline: 
**	- never runs the command
**	- does not open the following redirections.
*/

int	display_syntax_error(int err, char char_data, char *str_data)
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
	set_exit_status(2, 0);
	return (SYNTAX_ERROR);
}

/*
** SYNTAX ERROR from redirections : 
**
**	if there is no token after the redirection : it is the end of the line.
**	if the next token is not a word.
*/

int	check_syntax_error_redirection(t_token *token)
{
	if (!token->next)
	{
		display_syntax_error(ERR_SYMBOL, '\0', NULL);
		return (FAILURE);
	}
	if (is_token_words(token->next->type) == false)
	{
		display_syntax_error(ERR_SYMBOL, 0, token->next->word);
		return (FAILURE);
	}
	return (SUCCESS);
}
