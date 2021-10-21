/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redir.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 14:37:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_REDIR_H
# define MINISHELL_REDIR_H

# include "minishell.h"

/*
** Multi redirection possibility :
** like > file1 > file2 > file3
*/

typedef struct s_redirection	t_redir;
struct s_redirection
{
	char	*filename;
	int		type;
	t_redir	*next;
};

/*
** init structure t_redir : 
*/

t_redir		*malloc_redir(t_token *token);
void		free_list_redir(t_redir *redir);
void		free_this_redir(t_redir *redir); // static ?

/*
**	management t_redir
*/

void		add_back_redir(t_redir *redirection, t_redir *to_add);
t_redir		*add_redir(t_token *token);

#endif