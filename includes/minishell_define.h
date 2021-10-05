/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:51:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 14:05:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

# include "minishell.h"

//# define BUFFER_MAX		256

# define FAILURE		0
# define SUCCESS		1
# define EXIT			2

/*
** PROMPT : 
**	like standard shell bash : "$USER@minishell:pwd$ "
**
**	with colors : 
**	STR_COLOR_GREEN $USER STR_COLOR_STD : STR_COLOR_BLUE pwd STR_COLOR_STD $
**
**	if $USER don't exist : "minishell:pwd$ "
**
*/

# define PROMPT_SIZE			37
# define PROMPT_SIZE_NO_USER	36

# define S_COLOR_GREEN				"\33[32m"
# define S_COLOR_BLUE				"\33[94m"
# define S_COLOR_STD				"\33[0m"


typedef int	t_bool;



#endif
