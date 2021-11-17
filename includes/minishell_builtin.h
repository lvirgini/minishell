/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:24:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/17 16:42:32 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_H
# define MINISHELL_BUILTIN_H

# include "minishell.h"

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

typedef void (*t_callback)(char **arg, char **env, t_builtin *bi);

int		is_builtin(char *cmd, t_builtin *bi);

void	init_builtin(t_builtin *bi);
void	reset_builtin(t_builtin *bi);

char	*get_home_dir();
char	*get_current_dir(char *last_dir);

// int		exec_builtin(char **env, t_cmd *cmd, t_builtin *bi);

void	exec_echo(char **arg, char **env, t_builtin *bi);
void	exec_cd(char **arg, char **env, t_builtin *bi);
void	exec_pwd(char **arg, char **env, t_builtin *bi);
void	exec_export(char **arg, char **env, t_builtin *bi);
void	exec_unset(char **arg, char **env, t_builtin *bi);
void	exec_env(char **arg, char **env, t_builtin *bi);
void	exec_exit(char **arg, char **env, t_builtin *bi);

static const t_callback exec_builtin[7] = {exec_echo, exec_cd, exec_pwd, exec_export, exec_unset, exec_env, exec_exit};

#endif
