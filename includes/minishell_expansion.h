/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:38:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 16:26:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXPANSION_H
# define MINISHELL_EXPANSION_H

# include "minishell.h"

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
char		**expand_argv(char **argv, char **env);

/*
** Useful functions for t_expansion
*/

t_bool		need_expand_str(char *str);
t_bool		need_expand_argv(char **argv);

#endif