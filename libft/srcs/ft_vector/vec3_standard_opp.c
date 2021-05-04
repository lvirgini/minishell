/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_standard_opp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:45:12 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/11 15:16:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/*
** Opération standard sur des vecteurs a trois dimensions.
*/

t_vec3		add_vec3(t_vec3 a, t_vec3 b)
{
	return (create_vec3(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3		sub_vec3(t_vec3 a, t_vec3 b)
{
	return (create_vec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec3		mul_vec3(t_vec3 a, double t)
{
	return (create_vec3(t * a.x, t * a.y, t * a.z));
}

t_vec3		mul_vec3_vec3(t_vec3 a, t_vec3 b)
{
	return (create_vec3(a.x * b.x, a.y * b.y, a.z * b.z));
}
