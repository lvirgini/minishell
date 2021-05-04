/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:12 by lvirgini          #+#    #+#             */
/*   Updated: 2019/11/12 13:12:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	Ecrit le caractère (c) sur le file descriptor (fd).
*/

void	ft_putchar_fd(char c, int fd)
{
	if (fd)
		write(fd, &c, 1);
}
