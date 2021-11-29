/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:47:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 14:29:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ERROR_H
# define MINISHELL_ERROR_H

# define NB_ERR_SYNTAX	2
# define NB_ERROR 		7

enum	e_error_syntax
{
	ERR_SYMBOL,
	ERR_QUOTES_NOT_CLOSED,
};

/*
** Don't forget to update NB_ERROR and in function display_error() : 
**		string corresponding to ERR
**		exit status of errno
*/

enum	e_reason_cmd_not_work
{
	NO_ERROR,
	ERR_CMD_NOT_FOUND,
	ERR_CMD_NOT_EXECUTABLE,
	ERR_ABSOLUTE_PATH_NOT_FOUND,
	ERR_AMBIGUOUS,
	ERR_IS_A_DIRECTORY,
	ERR_STDIN_MINISHELL,
};

int		display_error(int error, char *object);
int		display_syntax_error(int err, char char_data, char *str_data);
void	display_heredoc_error(char *delimitor);
int		check_syntax_error_redirection(t_token *token);
void	exit_minishell(t_cmd **list_cmd, char **env);

#endif
