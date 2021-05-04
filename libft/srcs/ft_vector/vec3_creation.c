/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_advance_others.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:14:20 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/11 15:15:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec3		create_vec3(double x, double y, double z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec3		*malloc_vec3(double x, double y, double z)
{
	t_vec3 *res;

	if (!(res = malloc(sizeof(t_vec3))))
		return (NULL);
	*res = create_vec3(x, y, z);
	return (res);
}

t_vec3		copy_vec3(t_vec3 a)
{
	return (a);
}
