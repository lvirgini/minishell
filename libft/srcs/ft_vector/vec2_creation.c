/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:16:58 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/11 15:18:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2		create_vec2(double x, double y)
{
	t_vec2	res;

	res.x = x;
	res.y = y;
	return (res);
}

t_vec2		*malloc_vec2(double x, double y)
{
	t_vec2	*res;

	if (!(res = malloc(sizeof(t_vec2))))
		return (NULL);
	res->x = x;
	res->y = y;
	return (res);
}

t_vec2		copy_vec2(t_vec2 a)
{
	return (a);
}
