/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:24:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/19 13:31:21 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_H
# define MINISHELL_BUILTIN_H

# include "minishell.h"

# define S_TOO_MANY_ARGS "too many arguments"
# define TOO_MANY_ARGS -2

# define S_ECHO		"echo"
# define S_CD		"cd"
# define S_PWD		"pwd"
# define S_EXPORT	"export"
# define S_UNSET	"unset"
# define S_ENV		"env"
# define S_EXIT		"exit"

enum	e_env
{
	CMD_ECHO,
	CMD_CD,
	CMD_PWD,
	CMD_EXPORT,
	CMD_UNSET,
	CMD_ENV,
	CMD_EXIT,
};

typedef struct s_builtin
{
	int		set; //remove ?
	int		cmd;
	int		error;
	char	*home; //free a la fin NULL fatal ?
	char	*last; //free a la fin NULL fatal ?
}				t_builtin;

typedef void	(*t_callback)(char **arg, char **env, t_builtin *bi);

int		is_builtin(char *cmd, t_builtin *bi);

void	init_builtin(t_builtin *bi);
void	reset_builtin(t_builtin *bi);

char	*get_home_dir(void);
char	*get_current_dir(char *last_dir);

void	exec_echo(char **arg, char **env, t_builtin *bi);
void	exec_cd(char **arg, char **env, t_builtin *bi);
void	exec_pwd(char **arg, char **env, t_builtin *bi);
void	exec_export(char **arg, char **env, t_builtin *bi);
void	exec_unset(char **arg, char **env, t_builtin *bi);
void	exec_env(char **arg, char **env, t_builtin *bi);
void	exec_exit(char **arg, char **env, t_builtin *bi);

#endif
