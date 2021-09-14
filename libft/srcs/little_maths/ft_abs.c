/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:09:23 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:40:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return the absolute values (int, long, long long)
*/

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long	ft_labs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long long	ft_llabs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}
