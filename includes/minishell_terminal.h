/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_terminal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:56:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/16 18:00:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TERMINAL_H
# define MINISHELL_TERMINAL_H

int			create_terminal(t_env **env);
char		*get_prompt_display(t_env *env);
int			command_split(char *input);

#endif
