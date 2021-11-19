/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:38:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/18 16:55:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXPANSION_H
# define MINISHELL_EXPANSION_H

# include "minishell.h"

# define STR_ESCAPE	" \t\n"

typedef struct s_expansion	t_expansion;
struct s_expansion
{
	t_expansion	*next;
	char		*value;
};

/*
** init and free t_expansion
*/

t_expansion	*malloc_expansion(void);
void		free_expansion(t_expansion	*expansion);
void		free_list_expansion(t_expansion *expansion);

/*
** expansing functions
*/

int			expanser(t_cmd **list_cmd, char **env);
char		**expand(char *str, char **env);
char		**expand_argv(char **argv, char **env);
char		**expand_str(char *str, char **env);
int			expand_redirection(t_redir *redir, char **env);
char		**expand_dollar(char *str, char **env);
/*
** Useful functions for t_expansion
*/

t_bool		need_expand_str(char *str);

#endif