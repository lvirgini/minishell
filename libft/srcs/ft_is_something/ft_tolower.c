/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:57:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:05:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Renvoie le caractere (c) en minuscule s' il est Majuscule.
*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
