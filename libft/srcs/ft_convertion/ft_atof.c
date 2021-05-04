/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:38:23 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/08 13:19:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convertis la chaine pointee par (str) en double
*/

double		ft_atof(const char *str)
{
	int		integer_part;
	double	result;
	double	neg;

	integer_part = ft_atoi(str);
	neg = (*str == '-' && integer_part == 0) ? -1 : 1;
	while (*str && *str != '.')
		str++;
	result = (*str && *str == '.') ? (double)ft_atoi(++str) : 0;
	while (result >= 1)
		result /= 10;
	result += integer_part;
	return (result * neg);
}

/*
** Convertis la chaine pointee par (str) en double,
** Retourne 0 si la conversion a bien eu lieu.
*/

int			ft_atof_i(const char *str, double *result)
{
	int		integer_part;

	if (ft_atoi_i(str, &integer_part))
		return (-1);
	while (*str && *str != '.')
		str++;
	if (*str && *str == '.')
		*result = (double)ft_atoi(++str);
	else
		*result = 0;
	while (*result >= 1)
		*result /= 10;
	*result += integer_part;
	return (0);
}
