/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:17:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 12:20:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_CMD_H
# define MINISHELL_CMD_H

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

int			command_split(t_env *env, char *input);//

#endif
