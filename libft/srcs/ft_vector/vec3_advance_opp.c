/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_advance_opp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:29:48 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/11 15:23:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/*
** Le produit scalaire = dot product
*/

double		dot_vec3(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

/*
** La norme au carré d'un vecteur ||a||^2
*/

double		norme2_vec3(t_vec3 a)
{
	return ((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

/*
** la norme soit la longueur du vecteur ||a||
*/

double		norme_vec3(t_vec3 a)
{
	return (sqrt(norme2_vec3(a)));
}

/*
** Normaliser un vecteur c'est ramener sa longueur a 1
*/

t_vec3		normalize_vec3(t_vec3 a)
{
	double len;

	len = sqrt(norme2_vec3(a));
	return (create_vec3((a.x / len), (a.y / len), (a.z / len)));
}

/*
**a x b = 	a.y * b.z - a.z * b.y
**			a.z * b.x - a.x * b.z
**			a.x * b.y - a.y * b.x
*/

t_vec3		cross_vec3(t_vec3 a, t_vec3 b)
{
	return (create_vec3((a.y * b.z - a.z * b.y),
						(a.z * b.x - a.x * b.z),
						(a.x * b.y - a.y * b.x)));
}
