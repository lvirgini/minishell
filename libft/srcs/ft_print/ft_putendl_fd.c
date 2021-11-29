/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:39:06 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/07 13:20:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Écrit La chaine de caractères s sur le file
** descriptor donné, suivie d’un retour à la ligne.
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s && fd)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
