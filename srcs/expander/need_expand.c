/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:34:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 19:51:01 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	need_expand(char *s)
{
	size_t	i;

	if (!s)
		return (false);
	i = 0;
	while (s[i])
	{
		if (is_expansion(s[i]))
			return (true);
		i++;
	}
	return (false);
}
