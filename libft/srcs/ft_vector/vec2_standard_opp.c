/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_standard_opp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:41:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/11 15:17:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/*
** Opérations standards sur des vecteurs a deux dimensions.
*/

t_vec2		add_vec2(t_vec2 a, t_vec2 b)
{
	return (create_vec2((a.x + b.x), (a.y + b.y)));
}

t_vec2		sub_vec2(t_vec2 a, t_vec2 b)
{
	return (create_vec2((a.x - b.x), (a.y - b.y)));
}

t_vec2		mul_vec2(t_vec2 a, double t)
{
	return (create_vec2(t * a.x, t * a.y));
}
