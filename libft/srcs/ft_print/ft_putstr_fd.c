/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:16:34 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/29 18:09:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Ecrit la chaine de caractère (*s)  sur le file descriptor (fd).
*/

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int i;

	if (s && fd)
	{
		i = 0;
		while (s[i])
			++i;
		write(fd, s, i);
	}
}
