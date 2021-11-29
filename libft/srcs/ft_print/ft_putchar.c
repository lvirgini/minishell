/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:12 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/07 13:16:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	Ecrit le caractère (c) sur le file descriptor (fd).
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
