/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:56:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/23 22:31:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENV_H
# define MINISHELL_ENV_H

/*
** init env
*/

char	**malloc_list_env(int env_size);
char	*create_new_env(char *key, char *value);
void	free_list_env(char **env);

/*
** get env
*/

char	*get_env_value(char **env, char *key);
int		get_env_index(char **env, char *key);
int		get_list_env_size(char **env);

/*
** create minishell env
*/

char	**make_minishell_env(char *env[]);
char	**add_env(char **env, char *key, char *value);
int		duplicate_env(char **env, char **old, int size);
int		moving_env(char **env, char **old, int size);

/*
** Print env
*/

void	print_list_env(char **env);
void	print_this_env(char *env);

#endif
