/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirection.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:53:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 17:09:28 by eassouli         ###   ########.fr       */
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
int			create_pipe(t_cmd *cmd);
int			setup_all_redirections(t_cmd *cmd, char **env);
int			make_pipe_redirection(t_cmd *cmd);
int			setup_redirection(t_cmd *cmd, char **env);
//int			setup_inputs(t_redir *input);
//int			setup_outputs(t_redir *output);

/*
** Usefull
*/

void		save_std_io(int std_io[2]);
int			get_back_std_io(int std_io[2]);
void		close_pipe(int pipe[2]);

/*
** Here doc
*/

#endif
