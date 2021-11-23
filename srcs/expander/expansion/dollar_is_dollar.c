/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_is_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:25:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/23 16:26:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** complete expansion : it is solo "$" on minishell
*/

void	dollar_is_dollar(t_expansion *expansion)
{
	expansion->size_to_remove = 1;
	expansion->value = ft_split_set("$", STR_ESCAPE);
}
