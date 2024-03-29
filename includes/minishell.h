/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:24:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 14:21:07 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** includes lib headers
*/

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
** includes minishell headers
*/

# include "libft.h"
# include "minishell_define.h"
# include "minishell_utils.h"
# include "minishell_env.h"
# include "minishell_struct_token.h"
# include "minishell_struct_redir.h"
# include "minishell_struct_cmd.h"
# include "minishell_lexer.h"
# include "minishell_parser.h"
# include "minishell_expansion.h"
# include "minishell_error.h"
# include "minishell_redirection.h"
# include "minishell_execution.h"
# include "minishell_terminal.h"
# include "minishell_builtin.h"
# include "minishell_return.h"
# include "minishell_signals.h"

#endif
