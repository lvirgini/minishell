/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:39:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/25 13:37:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Imprime tous les entiers.
*/

void	print_int(char *s)
{
	int		len;
	char	*(*f)(int, char, char *, int *);

	if (*s)
	{
		if ((g_flag->precision == 0 && s[0] == '0'))
			s[0] = '\0';
		len = ft_strlen(s);
		f = &print_before;
		if (s[0] == '-' && len--)
			f = &print_before_sign;
		if (g_flag->precision > len)
			s = f(g_flag->precision, '0', s, &len);
		len = ft_strlen(s);
		if (g_flag->zero && g_flag->width > len && g_flag->left == 0)
			s = f(g_flag->width, '0', s, &len);
		f = &print_before;
		if (g_flag->left == 1)
			f = &print_after;
		if (g_flag->width > len)
			s = f(g_flag->width, ' ', s, &len);
		ft_putstr_fd(s, 1);
		g_flag->total_print += len;
		free(s);
	}
}

/*
** Imprime les hexadecimaux et les adresses.
*/

void	print_hexa(char *s)
{
	int		len;
	char	*(*f)(int, char, char *, int *);

	f = &print_before;
	if (g_flag->specifiers == 'p' && s)
		f = &print_before_0x;
	if (!s)
		s = ft_strdup("0");
	if (g_flag->precision == 0 && s[0] == '0' && ft_strlen(s) == 1)
		s[0] = '\0';
	len = ft_strlen(s);
	if (g_flag->precision > len)
		s = f(g_flag->precision, '0', s, &len);
	if (g_flag->zero && g_flag->width > len && g_flag->left == 0)
		s = f(g_flag->width, '0', s, &len);
	f = &print_before;
	if (g_flag->left == 1)
		f = &print_after;
	if (g_flag->width > len)
		s = f(g_flag->width, ' ', s, &len);
	ft_putstr_fd(s, 1);
	g_flag->total_print += len;
	free(s);
}
