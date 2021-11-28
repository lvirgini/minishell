/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:07:51 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 22:01:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS_H
# define MINISHELL_UTILS_H

# include "minishell.h"

typedef struct s_struct	t_struct;
struct	s_struct
{
	t_struct	*next;
	t_struct	*prev;
};

void	*struct_add_front(void *void_struct, void *void_to_add);
void	struct_add_back(void *structure, void *to_add);
void	struct_list_add_back(void *void_list, void *void_to_add);
size_t	struct_len(void *struct_first);

/*
** str utils
*/

void	print_str(char *str);
char	*pass_str_spaces(char *line);

#endif
