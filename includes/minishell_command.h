/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:50 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 22:26:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_COMMAND_H
# define MINISHELL_COMMAND_H

# include "minishell.h"

typedef struct s_cmd	t_cmd;
struct		s_cmd
{
	char	*path;
	char	**argv;
	int		type;
	int		pipe[2];
	char	*input;
	char	*output;
	pid_t	pid;
	int		exit_status;
	t_cmd	*next;
	t_cmd	*prev;
};

int	command_split(t_env *env, char *input);//

#endif