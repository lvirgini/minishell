/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:16 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/28 14:38:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** largeur de champs : si elle est dans un argument.
*/

static void		flag_width_is_arg(va_list args)
{
	if ((g_flag->width = va_arg(args, int)) < 0)
	{
		g_flag->width *= -1;
		g_flag->left = 1;
	}
}

/*
**	largeur de champs : si elle est inscrite dans la chaine format.
*/

static int		flag_width_is_digit(const char *format)
{
	char	*tmp;
	int		j;

	j = 0;
	while (ft_isdigit(format[j]))
		++j;
	tmp = ft_substr(format, 0, j);
	g_flag->width = ft_atoi(tmp);
	free(tmp);
	return (j);
}

/*
** Suite de précision : si c'est inscrit dans la chaine format.
*/

static int		flag_precision_is_digit(const char *s)
{
	char	*tmp;
	int		j;

	j = 0;
	while (ft_isdigit(s[j]))
		++j;
	if (j > 0)
	{
		tmp = ft_substr(s, 0, j);
		if ((g_flag->precision = ft_atoi(tmp)) < 0)
			g_flag->precision = -1;
		free(tmp);
	}
	return (j);
}

/*
** Récupère la precision.
*/

static int		flag_precision(const char *s, int i, va_list args)
{
	int		neg;

	neg = 1;
	if (s[i] == '-' && (i += 1) && (g_flag->left = 1))
		neg = -1;
	if (s[i] == '*' && (i += 1))
	{
		if ((g_flag->precision = va_arg(args, int)) < 0)
		{
			if (neg == -1 && (neg = 0) == 0)
				g_flag->width = g_flag->precision * -1;
			g_flag->precision = -1;
		}
	}
	else if (ft_isdigit(s[i]))
		i += flag_precision_is_digit(s + i);
	else
		g_flag->precision = 0;
	if (neg == -1 && g_flag->precision != 0)
	{
		g_flag->width = g_flag->precision;
		g_flag->precision = 0;
	}
	return (i);
}

/*
** Recuperation de tous les flags.
*/

int				flag_collect(const char *format, va_list args)
{
	int i;

	i = 0;
	if (format[i] == '%' && (g_flag->total_print += 1))
	{
		write(1, "%%", 1);
		return (i + 1);
	}
	while (ft_strchr("0123456789-*", format[i]))
	{
		if (format[i] == '0')
			g_flag->zero = 1;
		else if (format[i] == '-')
			g_flag->left = 1;
		else if (format[i] == '*')
			flag_width_is_arg(args);
		else if (ft_isdigit(format[i]))
			i += flag_width_is_digit(format + i) - 1;
		i++;
	}
	if (format[i] == '.')
		i = flag_precision(format, i + 1, args);
	return (type_dispatch(format, i, args));
}
