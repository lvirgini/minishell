/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:29:26 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/23 11:07:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Vérifie si le caractère (c) est un caractère imprimable, y compris l'espace.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
