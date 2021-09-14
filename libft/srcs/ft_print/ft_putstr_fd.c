/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:16:34 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:15:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Ecrit la chaine de caractère (*s)  sur le file descriptor (fd).
*/

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s && fd)
	{
		i = 0;
		while (s[i])
			++i;
		write(fd, s, i);
	}
}
