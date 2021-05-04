/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_advance_opp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 13:31:29 by lvirgini          #+#    #+#             */
/*   Updated: 2020/07/01 10:31:06 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/*
** Le produit scalaire = dot product
*/

double		dot_vec2(t_vec2 a, t_vec2 b)
{
	return ((a.x * b.x) + (a.y * b.y));
}

/*
**		VECTEUR COLINEAIRE : sur une même droite.
**		si vec_a = k * vec_b :	a.x = (k * b.x) => k = (b.x / a.x)
**								a.y = (k * b.y) => k = (b.y / a.y)
**		soit:
**								(b.x / a.x) - (b.y / a.y) = 0
**					* a.x		b.x - ((b.y * a.x) / a.y) = 0
**					* a.y		(b.x * a.y) - (b.y * a.x) = 0
*/

int			vec2_colineaire(t_vec2 a, t_vec2 b)
{
	if (((a.x * b.y) - (b.x * a.y)) == 0)
		return (0);
	else
		return (-1);
}

/*
** La norme au carré d'un vecteur ||a||^2
*/

double		norme2_vec2(t_vec2 a)
{
	return ((a.x * a.x) + (a.y * a.y));
}

/*
** la norme soit la longueur du vecteur ||a||
*/

double		norme_vec2(t_vec2 a)
{
	return (sqrt(norme2_vec2(a)));
}

/*
** Normaliser un vecteur c'est ramener sa longueur a 1.
*/

t_vec2		normalize_vec2(t_vec2 a)
{
	double len;

	len = sqrt(norme2_vec2(a));
	return (create_vec2((a.x / len), (a.y / len)));
}
