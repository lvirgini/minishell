/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:33:09 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/03 12:27:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** La fonction atoi convertit le début la chaine pointée par *s
** en entier de type int.
*/

static int		ft_is_ok(long int result, int sign)
{
	result *= sign;
	if (result > 2147483647)
		return (0);
	if (result < -2147483648)
		return (0);
	return ((int)result);
}

static int		ft_is_ok_atoi_i(int *ret, long int result, int sign)
{
	result *= sign;
	if (result > 2147483647)
		return (0);
	if (result < -2147483648)
		return (0);
	*ret = (int)result;
	return (1);
}

int				ft_atoi(const char *s)
{
	int			i;
	int			max;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '\0')
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		++i;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign *= -1;
	}
	max = 0;
	while (s[i] >= '0' && s[i] <= '9' && max++ < 10)
	{
		result = result * 10 + (s[i] - '0');
		++i;
	}
	return (ft_is_ok(result, sign));
}

/*
** La fonction atoi convertit le début la chaine pointée par *s
** en entier de type int.
** Retourne 0 = false
** Retoune 1 = true
*/

int				ft_atoi_i(const char *s, int *result)
{
	size_t		i;
	int			max;
	int			sign;
	long int	res;

	sign = 1;
	i = 0;
	res = 0;
	max = 0;
	if (s[i] == '\0')
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign *= -1;
	}
	while (ft_isdigit(s[i]) && max++ < 10)
		res = res * 10 + (s[i++] - '0');
	if (s[i])
		return (0);
	return (ft_is_ok_atoi_i(result, res, sign));
}
