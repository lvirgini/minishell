/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:56:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 11:19:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENV_H
# define MINISHELL_ENV_H

typedef struct s_env	t_env;
struct		s_env
{
	char	*key;
	char	*value;
	t_env	*next;
};

/*
** malloc, free, add, remove
*/

void		free_all_t_env(t_env *env);
t_env		*add_new_env(char *key, char *value);
int			add_front_env(t_env **env, t_env *to_add);
int			edit_or_add_t_env(t_env **env, char *key, char *value);
t_env		*get_complete_env(char **env, char *shell_name);
int			check_and_set_minimum_t_env(t_env **env, char *shell_name);

/*
** others get datas
*/

void		print_env(t_env *env);
char		*get_value_t_env(t_env *env, char *key);
t_env		*get_this_env(t_env *env, char *key);

#endif
