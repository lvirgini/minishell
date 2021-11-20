/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:38:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 14:41:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXPANSION_H
# define MINISHELL_EXPANSION_H

# include "minishell.h"

# define STR_ESCAPE	" \t\n"
# define NB_EXPANDER	3


typedef struct s_expansion	t_expansion;
struct s_expansion
{
	t_expansion	*next;
	char		**value;
	size_t		start_of_the_expand;
	size_t		size_to_remove;
};

//typedef void	(*t_callback)(char **arg, char **env, t_builtin *builtin);
typedef t_expansion *(*t_ft_expand)(char *s, char **env);

/*
** init and free t_expansion
*/

t_expansion	*malloc_expansion(void);
void		free_expansion(t_expansion	*expansion);
void		free_list_expansion(t_expansion *expansion);

/*
** expansing functions
*/

t_expansion	*expand_str(char *s, char **env);
//t_expansion	*expand_list(char **list, char **env);


t_expansion *expand_simple_quote(char *s, char **env);
t_expansion *expand_double_quote(char *s, char **env);
t_expansion *expand_dollar(char *s, char **env);




int			expanser(t_cmd **list_cmd, char **env);
char		**expand(char *str, char **env);
char		**expand_argv(char **argv, char **env);
//char		**expand_str(char *str, char **env);
int			expand_redirection(t_redir *redir, char **env);
//char		**expand_dollar(char *str, char **env);


/*
** Useful functions for t_expansion
*/

t_bool		is_expansion(char c);
t_bool		need_expand(char *s);
t_expansion	*get_expansion(char *s, char **env);

#endif
