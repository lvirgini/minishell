/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:30:06 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/23 11:07:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Vérifie si le caractère (c) est compris dans la table ascii non étendu.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
