/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:24:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 11:17:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_H
# define MINISHELL_BUILTIN_H

# include "minishell.h"

# define S_ECHO		"echo"
# define S_CD		"cd"
# define S_PWD		"pwd"
# define S_EXPORT	"export"
# define S_UNSET	"unset"
# define S_ENV		"env"
# define S_EXIT		"exit"

enum	e_env
{
	CMD_ECHO,
	CMD_CD,
	CMD_PWD,
	CMD_EXPORT,
	CMD_UNSET,
	CMD_ENV,
	CMD_EXIT,
};

#endif
