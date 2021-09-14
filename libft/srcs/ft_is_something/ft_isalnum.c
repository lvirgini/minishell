/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:26:34 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:04:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** equivalent de isalpha + isdigit :
** vérifie si le caractère (c) est alphabetique ou numérique.
*/

int	ft_isalnum(int c)
{
	return ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122));
}
