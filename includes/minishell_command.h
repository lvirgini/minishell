/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:50 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/18 22:08:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_COMMAND_H
# define MINISHELL_COMMAND_H

# include "minishell.h"

/*
** Multi redirection possibility :
** like > file1 > file2 > file3
*/

typedef struct s_redirection	t_redir;
struct s_redirection
{
	char	*filename;
	int		type_redir;
	t_redir	*next;
};

/*
** One command structure : 
**
** path		= path found of executable command
** argv		= all arguments of this command
** type		= if command is PIPE, SIMPLE CMD
** input	= all char *filename for redirection of stdin
** output	= all char *filename for redirection of stdout
** pid		= pid of the process execution
*/

typedef struct s_cmd	t_cmd;
struct		s_cmd
{
	char	*path;		// echo
	char	**argv; 	// -e
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

t_cmd		*malloc_t_cmd(t_cmd *prev);
t_cmd		**malloc_list_t_cmd(void);
void		free_t_cmd(t_cmd *cmd);
void		free_list_t_cmd(t_cmd **cmd);

/*
**
*/

t_cmd		*get_next_cmd(t_cmd *prev, t_token **token);

/*
**
*/

void		add_back_t_redir(t_redir *redirection, t_redir *to_add);
t_redir		*add_t_redir(t_token *token);
t_redir		*parse_redir( t_token *token);
int			parse_all_redirection(t_cmd *cmd, t_token **all_token);
int			is_token_control_operator(int token_type);

/*
** t_funnction parse_token
*/

typedef int	(*t_ft_parser)(t_cmd *, t_token *);

int			parse_pipe(t_cmd *cmd, t_token *token);
int			parse_input(t_cmd *cmd, t_token *token);
int			parse_output(t_cmd *cmd, t_token *token);
int			parse_here_doc(t_cmd *cmd, t_token *token);
int			parse_append(t_cmd *cmd, t_token *token);

#endif
