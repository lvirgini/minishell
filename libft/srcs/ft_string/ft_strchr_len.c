/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:01:05 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/07 14:02:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	Recherche un caractère (c) dans une chaine de caratere (*s).
** 	Renvoie l'index de la première occurence, sinon -1;
*/

int			ft_strchr_len(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return (i);
		++i;
	}
	return (-1);
}
