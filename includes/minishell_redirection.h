/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirection.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:53:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/09 11:54:18 by lvirgini         ###   ########.fr       */
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

int			setup_redirections(t_cmd *cmd);
int			make_pipe_redirection(t_cmd *cmd);
int			setup_inputs(t_redir *input);
int			setup_outputs(t_redir *output);
void		save_std_io(int std_io[2]);
int			get_back_std_io(int std_io[2]);

/*
** Here doc
*/

#endif
