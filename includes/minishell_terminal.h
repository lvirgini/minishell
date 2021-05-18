/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_terminal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:56:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 11:19:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TERMINAL_H
# define MINISHELL_TERMINAL_H

typedef struct s_cmd	t_cmd;

struct		s_cmd
{
	char	*name;
	char	*options;
	char	*args;
	int		next_operator;
	t_cmd	*next;
};

int			create_terminal(t_env **env);
char		*get_prompt_display(t_env *env);
int			command_split(t_env *env, char *input);

#endif
