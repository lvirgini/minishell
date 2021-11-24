/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct_redir.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 17:32:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_REDIR_H
# define MINISHELL_STRUCT_REDIR_H

# include "minishell.h"

/*
** Multi redirection possibility :
** like > file1 > file2 > file3
*/

typedef struct s_redirection	t_redir;
struct s_redirection
{
	t_redir	*next;
	char	*filename;
	int		type;
	t_bool	need_expand;
};

typedef struct s_heredoc		t_hdoc;
struct s_heredoc
{
	t_hdoc	*next;
	t_bool	need_expand;
	int		priority;
	char	*delimitor;
	char 	**data;
};

/*
** init structure t_redir : 
*/

t_redir		*create_redir(int type, char *filename);
void		free_list_redir(t_redir *redir);
void		free_this_redir(t_redir *redir); // static ?

/*
**	management heredoc : 
*/

t_hdoc      *malloc_heredoc(void);
t_hdoc     *create_heredoc(char *delimitor);
void    	free_list_heredoc(t_hdoc *heredoc);

#endif
