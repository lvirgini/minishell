/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_expansion_add_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:48:19 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 19:58:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_expansion	*add_back_expansion(t_expansion *first, t_expansion *to_add)
{
	if (!first)
		return (to_add);
	struct_add_back(first, to_add);
	return (first);
}
