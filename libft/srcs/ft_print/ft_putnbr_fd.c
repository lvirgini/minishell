/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:40:09 by lvirgini          #+#    #+#             */
/*   Updated: 2019/11/12 13:58:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Ecrit l'integer (n) sur le file descriptor (fd).
*/

void	ft_putnbr_fd(int n, int fd)
{
	long int nb;

	if (fd)
	{
		nb = n;
		if (nb < 0)
		{
			nb = -nb;
			write(fd, "-", 1);
		}
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
		else
		{
			nb += '0';
			write(fd, &nb, 1);
		}
	}
}
