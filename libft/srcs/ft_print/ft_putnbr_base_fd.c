/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:53:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:16:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verif_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (!base[i] || !base[i + 1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static void	ft_putnbr_recursif(int nbr, char *base, int len, int fd)
{
	if (nbr >= len)
	{
		ft_putnbr_recursif(nbr / len, base, len, fd);
		ft_putnbr_recursif(nbr % len, base, len, fd);
	}
	if (nbr < len)
		write(fd, &base[nbr], 1);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int		len;

	len = ft_strlen(base);
	if (ft_verif_base(base))
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write(fd, "-", 1);
		}
		ft_putnbr_recursif(nbr, base, len, fd);
	}
}
