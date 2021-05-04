/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:09:23 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/03 10:49:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the absolute values (int, long, long long and double)
*/

int			ft_abs(int n)
{
	return (n < 0 ? n * -1 : n);
}

long		ft_labs(long n)
{
	return (n < 0 ? n * -1 : n);
}

long long	ft_llabs(long long n)
{
	return (n < 0 ? n * -1 : n);
}

double		ft_fabs(double n)
{
	return (n > 0.0 ? n *= -1 : n);
}
