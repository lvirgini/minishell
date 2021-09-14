/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:12 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:04:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Renvoie le caractère (c) en Majuscule s'il est un minuscule.
*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
