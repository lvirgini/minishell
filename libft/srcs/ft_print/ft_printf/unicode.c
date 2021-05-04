/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:35:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/28 14:41:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Visuel des masques binaires
**	.
**	mask0 = 									0XXX XXXX  1 octet  =  8 bits
**	mask1 = 						110X XXXX   10XX XXXX  2 octets = 16 bits
**	mask2 = 			1110 XXXX	10XX XXXX	10XX XXXX  3 octets = 24 bits
**	mask3 = 1111 0XXX	10XX XXXX	10XX XXXX	10XX XXXX  4 octets = 32 bits
**	.
**	1 octet  =  <=  7 bits ( 8 -  1 mask)
**	2 octets =  <= 11 bits (16 -  5 mask)
**	3 octets =  <= 16 bits (24 -  8 mask)
**	4 octets =  <= 21 bits (32 - 11 mask)
**	.
**	char flag->arg[size] = [octet1][octet2][octet3][octet4]
*/

/*
**  Récupère la taille du wchar pour envoi en conversion
*/

int		size_unicode(wchar_t arg)
{
	char	size;
	int		nb_oct;

	size = 0;
	while ((unsigned)arg >> size)
		size++;
	if (size < 8)
		nb_oct = 1;
	else if (size < 12)
		nb_oct = 2;
	else if (size < 17)
		nb_oct = 3;
	else
		nb_oct = 4;
	return (nb_oct);
}

/*
** Masque binaires = visuel binaire.
**	.
** 	0x80 =	10xx xxxx
** 	0x3F = 	0011 1111
**	.
**  0xC0 =	110x xxxx
** 	0x1F =	0001 1111
**	.
** 	0xE0 = 	1110 xxxx
** 	0xF	 = 	0000 1111
**	.
** 	0xF0 = 	1111 0xxx
**  7	 =	0000 0111
**	.
**		Exmple si 4 octets :
**	.
**		(1111 0)000 | (10)10 0010	| (10)00 0001	| (10)00 0101
**			>> 18	|	>> 12		|	>> 6		|
**	.
*/

int		print_unicode(wchar_t arg, int nb_oct)
{
	unsigned char	octet[nb_oct];

	ft_bzero(octet, nb_oct);
	octet[0] = (unsigned char)arg;
	if (nb_oct == 2)
	{
		octet[0] = (((unsigned)arg >> 6) & 0x1F) | 0xC0;
		octet[1] = ((unsigned)arg & 0x3F) | 0x80;
	}
	else if (nb_oct == 3)
	{
		octet[0] = (((unsigned)arg >> 12) & 0xF) | 0xE0;
		octet[1] = (((unsigned)arg >> 6) & 0x3F) | 0x80;
		octet[2] = ((unsigned)arg & 0x3F) | 0x80;
	}
	else if (nb_oct == 4)
	{
		octet[0] = (((unsigned)arg >> 18) & 7) | 0xF0;
		octet[1] = (((unsigned)arg >> 12) & 0x3F) | 0x80;
		octet[2] = (((unsigned)arg >> 6) & 0x3F) | 0x80;
		octet[3] = ((unsigned)arg & 0x3F) | 0x80;
	}
	if (nb_oct != 0 && (g_flag->total_print += nb_oct))
		write(1, octet, nb_oct);
	return (nb_oct);
}
