/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:47:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 11:15:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ERROR_H
# define MINISHELL_ERROR_H

enum	e_error
{
	ERR_MALLOC,
};

enum	e_reason_cmd_not_work
{
	NOT_FOUND,
};

void		display_command_error(t_env *env, char *cmd, int reason);

#endif
