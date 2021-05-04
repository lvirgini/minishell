/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:12:08 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/28 14:40:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Récupère l'argument sans specification de taille.
*/

static int		type_classic(const char *format, int i, va_list args)
{
	if ((ft_strchr("di", format[i])))
		g_flag->arg = (int)va_arg(args, int);
	else if ((ft_strchr("cuxX", format[i])))
		g_flag->uarg = (unsigned int)va_arg(args, unsigned int);
	else if ((format[i] == 'p'))
		g_flag->uarg = (t_ull)va_arg(args, t_ull);
	else if ((format[i] == 's'))
		g_flag->s = va_arg(args, char *);
	else if ((format[i] == '%'))
		;
	else
		g_flag->arg_error = 1;
	return (i);
}

/*
** Récupère l'argument avec les flags (l) ou (ll).
*/

static int		type_long(const char *format, int i, va_list args)
{
	while (format[i] != 'l')
		i++;
	if (format[i + 1] == 'l')
	{
		if ((ft_strchr("di", format[i + 2])))
			g_flag->arg = (long long)va_arg(args, long long);
		else if ((ft_strchr("uxX", format[i + 2])))
			g_flag->uarg = (t_ull)va_arg(args, t_ull);
		else
			g_flag->arg_error = 1;
		return (i + 2);
	}
	if ((ft_strchr("di", format[i + 1])))
		g_flag->arg = (long)va_arg(args, long);
	else if ((ft_strchr("uxX", format[i + 1])))
		g_flag->uarg = (unsigned long int)va_arg(args, unsigned long int);
	else if (format[i + 1] == 's')
		g_flag->ls = va_arg(args, wchar_t *);
	else if (format[i + 1] == 'c')
		g_flag->uarg = (int)va_arg(args, int);
	else
		g_flag->arg_error = 1;
	return (i + 1);
}

/*
** Récupère l'argument avec les g_flags (h) ou (hh).
*/

static int		type_short(const char *format, int i, va_list args)
{
	while (format[i] != 'h')
		i++;
	if (format[i + 1] == 'h')
	{
		if ((ft_strchr("di", format[i + 2])))
			g_flag->arg = (char)va_arg(args, int);
		else if ((ft_strchr("uxX", format[i + 2])))
			g_flag->uarg = (unsigned char)va_arg(args, int);
		else
			g_flag->arg_error = 1;
		return (i + 2);
	}
	if ((ft_strchr("di", format[i + 1])))
		g_flag->arg = (short int)va_arg(args, int);
	else if ((ft_strchr("uxX", format[i + 1])))
		g_flag->uarg = (unsigned short int)va_arg(args, int);
	else
		g_flag->arg_error = 1;
	return (i + 1);
}

/*
** Recherche de la taille de l'argument à récupérer.
*/

static int		type_size(const char *format, int i, va_list args)
{
	int		(*f)(const char *, int, va_list args);
	int		j;

	j = 0;
	f = &type_classic;
	while (ft_strchr("hl", format[i + j]))
	{
		if (format[i + j] == 'h')
			f = &type_short;
		else
			f = &type_long;
		++j;
	}
	g_flag->specifiers = format[i + j];
	return (f(format, i, args));
}

/*
** recherche du type d'argument, et l'envoie pour son impression.
*/

int				type_dispatch(const char *format, int i, va_list args)
{
	i = type_size(format, i, args);
	if (g_flag->arg_error && (g_flag->total_print += 1) && (write(1, "%%", 1)))
		return (1);
	if (format[i] == '%' && (g_flag->uarg = '%') == '%')
		print_percent();
	g_flag->zero = g_flag->precision >= 0 ? 0 : g_flag->zero;
	if (format[i] == 'c')
	{
		if (format[i - 1] == 'l')
			print_wchar(size_unicode(g_flag->uarg));
		print_character();
	}
	else if (format[i] == 's')
		print_string();
	else if (format[i] == 'p')
		print_hexa((convert_adress(format[i - 1])));
	else if ((format[i] == 'd' || format[i] == 'i'))
		print_int(ft_lltoa(g_flag->arg));
	else if (format[i] == 'u')
		print_int(ft_ulltoa(g_flag->uarg));
	else if (format[i] == 'x' || format[i] == 'X')
		print_hexa((convert_hexadecimal()));
	return (i + 1);
}
