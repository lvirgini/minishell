/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_terminal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:56:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 15:32:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TERMINAL_H
# define MINISHELL_TERMINAL_H

# include "minishell.h"

typedef	struct s_prompt	t_prompt;

struct s_prompt
{
	char	*user;
	char	*minishell;
	char	*cwd;
	char	*end;
	char	*formatted;
};

/*
** initialisation and free
*/

t_prompt	*init_prompt(char *user, char *pwd);
void		free_t_prompt(t_prompt *prompt);

/*
** get_prompt for readline()
*/

t_prompt	*get_prompt(t_env *env, t_prompt *prompt);

int			create_terminal(t_env **env);
char		*get_prompt_display(t_env *env);
int			command_split(t_env *env, char *input);

#endif
