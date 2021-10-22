/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct_cmd.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:50 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/22 13:31:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_CMD_H
# define MINISHELL_STRUCT_CMD_H

# include "minishell.h"

/*
** One command structure : 
**
** path		= path found of executable command
** argv		= all arguments of this command
** type		= if command is PIPE, SIMPLE CMD
** input	= all char *filename in t_redir for redirection of stdin
** output	= all char *filename in t_redir for redirection of stdout
** pid		= pid of the process execution
*/

typedef struct s_cmd	t_cmd;
struct		s_cmd
{
	char	*path;
	char	**argv;
	int		type;
	int		pipe[2];
	t_redir	*input;
	t_redir	*output;
	pid_t	pid;
	int		exit_status;
	t_cmd	*next;
	t_cmd	*prev;
};

enum e_cmd_type
{
	CMD_SIMPLE,
	CMD_PIPE,
};

/*
** Setup structure t_cmd : free and malloc
*/

t_cmd		*malloc_cmd(void);
t_cmd		**malloc_list_cmd(void);
void		free_cmd(t_cmd *cmd);
void		free_list_cmd(t_cmd **cmd);
void		add_back_cmd(t_cmd **list_cmd, t_cmd *to_add);

#endif
