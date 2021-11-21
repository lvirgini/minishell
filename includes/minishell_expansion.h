/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:38:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 17:49:10 by lvirgini         ###   ########.fr       */
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

typedef t_expansion *(*t_ft_expand)(char *s, char **env);

/*
** init and free t_expansion
*/

t_expansion	*malloc_expansion(void);
void		free_list_expansion(t_expansion *expansion);
t_expansion	*add_back_expansion(t_expansion *first, t_expansion *to_add);

/*
** expansing functions
*/

t_expansion	*expand_str(char *s, char **env);
//t_expansion	*expand_list(char **list, char **env);

/*
** expand_something
*/

int			expanser(t_cmd **list_cmd, char **env);
t_expansion	*get_expansion(char *s, char **env);
t_expansion *expand_simple_quote(char *s, char **env);
t_expansion *expand_double_quote(char *s, char **env);
t_expansion *expand_dollar(char *s, char **env);

//char		**expand(char *str, char **env);
void		expand_argv(t_cmd *cmd, char **env);


int			expand_redirection(t_redir *redir, char **env);
char		*fusion_str_expansion(char *old_s, t_expansion *expansion);

/*
** Useful functions for t_expansion
*/

t_bool		is_expansion(char c);
t_bool		need_expand(char *s);
size_t		get_expand_removed_len(t_expansion *expansion);
size_t		dollar_len(char *s);
t_bool		is_dollar_env_value_syntax(char c);
char		isolate_key(char *s, t_expansion *expansion);
size_t		count_expansion_split(t_expansion *expansion);


#endif
