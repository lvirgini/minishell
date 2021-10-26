/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:24:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 14:56:40 by lvirgini         ###   ########.fr       */
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
# include "minishell_struct_token.h"
# include "minishell_struct_redir.h"
# include "minishell_struct_cmd.h"
# include "minishell_lexer.h"
# include "minishell_parser.h"
# include "minishell_expansion.h"
# include "minishell_error.h"
# include "minishell_terminal.h"
# include "test_minishell.h" //

typedef	struct s_structure	t_structure;
struct	s_structure
{
	t_structure *next;
};
void	add_back_structure(t_structure *structure, t_structure *to_add);
void	testing_structure(void);

/*
** list str utils
*/

char	**malloc_list(int size);
void	free_list(char **list);
void	free_n_list(char **list, size_t nb);
size_t	list_strlen(char **list);
int		moving_list(char **list, char **old_list, int max);
int		duplicate_list(char **list, char **old_list, int max);

/*
** str utils
*/

char	*pass_str_spaces(char *line);

#endif
