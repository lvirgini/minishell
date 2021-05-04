/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:47:02 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/28 14:43:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Reinitialise les elements de la structure.
*/

static void		struct_init(void)
{
	g_flag->left = 0;
	g_flag->zero = 0;
	g_flag->width = 0;
	g_flag->precision = -1;
	g_flag->specifiers = 0;
	g_flag->arg = 0;
	g_flag->uarg = 0;
	g_flag->s = NULL;
	g_flag->ls = NULL;
	g_flag->arg_error = 0;
}

/*
** Malloc la structure complete.
*/

static t_flag	*struct_malloc(void)
{
	if (!(g_flag = (t_flag *)malloc(sizeof(*g_flag))))
		return (NULL);
	g_flag->total_print = 0;
	struct_init();
	return (g_flag);
}

/*
** Free de la structure et renvoie le total imprimé par printf.
*/

static int		struct_clean_end(void)
{
	int total_print;

	total_print = g_flag->total_print;
	free(g_flag);
	return (total_print);
}

/*
**	lecture de la chaine *format.
**	Recherche du %
**	Print la partie de la chaine en s'arretant au %
**	Envoie pour verification, recuperation, conversion et print de l'argument.
*/

t_flag	*g_flag;

int				ft_printf(const char *restrict format, ...)
{
	unsigned int	len;
	va_list			args;

	va_start(args, format);
	if (!format || !(g_flag = struct_malloc()))
		return (-1);
	while (format)
	{
		len = ft_strchr_len(format, '%');
		ft_putstr_fd_maxlen((char *)format, 1, len);
		g_flag->total_print += len;
		if (format[len] == '\0')
			return (struct_clean_end());
		if (format[len] == '%')
		{
			len++;
			len += flag_collect(format + len, args);
			struct_init();
		}
		format += len;
	}
	va_end(args);
	return (struct_clean_end());
}
