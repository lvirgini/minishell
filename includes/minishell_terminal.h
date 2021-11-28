/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_terminal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:56:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/28 12:34:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TERMINAL_H
# define MINISHELL_TERMINAL_H

# define PROMPT_LEN 		34
# define GREEN_COLOR		"\33[32m"

typedef struct s_prompt	t_prompt;

struct s_prompt
{
	char	*user;
	char	*cwd;
	char	*formatted;
};

/*
** initialisation and free
*/

t_prompt	*initialize_prompt(char **env);
void		free_t_prompt(t_prompt *prompt);

/*
** Change and update prompt
*/

t_bool		change_prompt_user(t_prompt *prompt, char *actual_user);
int			layout_prompt(t_prompt *prompt);
int			update_prompt(char **env, t_prompt **prompt);

/*
** get_prompt for readline()
*/

void		make_terminal(char***env);

#endif
