/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:24:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 13:32:23 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_H
# define MINISHELL_BUILTIN_H

# include "minishell.h"

# define S_TOO_MANY_ARGS ": too many arguments\n"
# define S_TOO_MANY_ARGS_CD "too many arguments\n"
# define S_NO_FILE ": No such file or directory\n"
# define S_NO_DIR ": Not a directory\n"
# define S_PERM ": Permission denied\n"
# define S_NOT_ID "\': not a valid identifier\n"
# define S_NO_HOME "cd: HOME not set\n"
# define S_NO_OLDPWD "cd: OLDPWD not set\n"
# define S_NOT_NUM ": numeric argument required\n"

# define S_SHELL "SHELL=./minishell" //
# define S_SHLVL "SHLVL="
# define S_SHLVL1 "SHLVL=1"
# define S_OLDPWD "OLDPWD="

# define SHLVL "SHLVL"
# define OLDPWD "OLDPWD"

# define NOT_BUILTIN -1
# define TOO_MANY_ARGS -2
# define NO_FILE -3
# define NOT_ID -4

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

typedef void	(*t_callback)(char **arg, char ***env);

int		is_builtin(char *cmd);

int		exec_builtin(int builtin, char ***env, t_cmd *cmd);

char	*get_home_dir(char **env);
char	*get_current_dir(void);
char	*get_old_dir(char **env);

void	exec_echo(char **arg, char ***env);

void	exec_cd(char **arg, char ***env);
void	cd_errors(int error, char *arg, char *path);
void	cd_home(char **arg, char ***env);

void	exec_pwd(char **arg, char ***env);

void	exec_export(char **arg, char ***env);
int		is_valid_key(char *str);

void	export_shlvl(char ***env);
void	export_oldpwd(char *old, char ***env);
void	export_shell(char ***env);
void	unset_oldpwd(char ***env);

void	exec_unset(char **arg, char ***env);

void	exec_env(char **arg, char ***env);

void	exec_exit(char **arg, char ***env);

#endif
