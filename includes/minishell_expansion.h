/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:38:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 19:27:17 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXPANSION_H
# define MINISHELL_EXPANSION_H

# include "minishell.h"

typedef struct s_expansion	t_expansion;
struct s_expansion
{
	char		*value;
	t_expansion	*next;
};

t_bool		need_expand_argv(char **argv);

#endif