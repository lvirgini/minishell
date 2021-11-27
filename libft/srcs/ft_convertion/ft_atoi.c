/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:02:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 11:58:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  The atoi() function converts the initial portion of the string pointed
**	to by *s to int.
**	return 0 if > INT_MAX / < INT_MIN / no number.
*/

static int	get_first_sign_from_str(const char *s, size_t *i)
{
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
		{
			*i += 1;
			return (-1);
		}
		*i += 1;
	}
	return (1);
}

static int	if_valid_integer(long int result)
{
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return ((int)result);
}

int	ft_atoi(const char *s)
{
	size_t		i;
	int			max;
	int			sign;
	long int	result;

	i = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (ft_isspace(s[i]))
		i++;
	sign = get_first_sign_from_str(s, &i);
	result = 0;
	max = 11;
	while (ft_isdigit(s[i]) && max-- > 0)
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (if_valid_integer(result * sign));
}

/*
** same as atoi but return true if success convertion, or false if not;
*/

int	ft_atoi_i(const char *s, int *ret)
{
	size_t		i;
	int			max;
	int			sign;
	long int	result;

	i = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (ft_isspace(s[i]))
		i++;
	sign = get_first_sign_from_str(s, &i);
	result = 0;
	max = 11;
	while (ft_isdigit(s[i]) && max-- > 0)
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
		return (false);
	*ret = (int)result;
	return (true);
}
