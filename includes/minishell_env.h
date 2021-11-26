/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:56:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 09:59:36 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENV_H
# define MINISHELL_ENV_H

/*
** get env
*/

char	*get_env_value(char **env, char *key);
int		get_env_index(char **env, char *key);
int		get_list_env_size(char **env); //

/*
** create minishell env
*/

char	**make_minishell_env(char *env[]);
char	**list_cdup(char **src, char c);
int		list_ccpy(char **dst, char **src, char c);
size_t	listclen(char **list, char c);

/*
** modify env
*/

void	add_new_env(char ***env, char *to_add);
int		edit_env(char **env, int index, char *to_edit);

#endif
