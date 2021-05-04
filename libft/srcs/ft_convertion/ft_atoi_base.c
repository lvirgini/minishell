/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:54:33 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/22 13:39:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_pass_isspace(char *str)
{
	int i;

	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
		++i;
	return (i);
}

static int		ft_sign(char *str, int *i)
{
	int sign;

	sign = 1;
	while ((str[*i] == '+') || (str[*i] == '-'))
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

static int		ft_verif_base(char *base)
{
	int i;
	int j;

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

int				ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int sign;
	int res;
	int len;

	res = 0;
	len = ft_strlen(base);
	if (!str[0] || len <= 1 || !ft_verif_base(base))
		return (0);
	i = ft_pass_isspace(str);
	sign = ft_sign(str, &i);
	while (str[i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			++j;
		if (base[j] != '\0')
			res = res * len + j;
		++i;
	}
	return (res * sign);
}
