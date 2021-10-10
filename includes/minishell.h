/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:24:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/10 15:53:13 by lvirgini         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>

/*
** includes minishell headers
*/

# include "libft.h"
# include "minishell_define.h"
# include "minishell_env.h"
# include "minishell_command.h"
# include "minishell_error.h"
# include "minishell_terminal.h"
# include "minishell_token.h"
# include "test_minishell.h" //

int			make_terminal(t_env	**env);

#endif
