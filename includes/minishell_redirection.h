/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirection.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:53:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 21:51:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_REDIRECTION_H
# define MINISHELL_REDIRECTION_H

# include "minishell.h"

enum	e_stdio
{
	IN,
	OUT,
};

/*
** setup input / output
*/

int			setup_pipe_redirection(t_cmd *cmd);
int			setup_all_redirections(t_cmd *cmd, char **env);
int			setup_redirection(t_cmd *cmd, char **env);
int			setup_heredoc_input(t_hdoc *heredoc);

/*
** Usefull
*/

int			create_pipe(t_cmd *cmd);
void		save_std_io(int std_io[2]);
int			get_back_std_io(int std_io[2]);
void		close_parent_pipe(t_cmd *cmd);
void		close_pipe(int pipe[2]);
void		close_fd(int fd);

/*
** Here doc
*/

int			make_heredoc(t_hdoc *heredoc, char **env);

#endif
