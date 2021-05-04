/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:33:14 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/28 14:41:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Print (len) espaces.
*/

static int		print_space(unsigned int len)
{
	char	s[len];

	ft_memset((char *)s, ' ', len);
	ft_putstr_fd_maxlen(s, 1, len);
	return (len);
}

/*
** Print des characteres de la chaine de charactere comportant des unicodes.
*/

static void		print_ls(wchar_t *ls, int len)
{
	int		i;
	int		oct;
	int		total_oct;

	i = 0;
	total_oct = 0;
	while (ls[i])
	{
		oct = size_unicode(ls[i]);
		if ((total_oct += oct) <= len)
			print_unicode(ls[i], oct);
		i++;
	}
}

/*
** Impression des CHAR *
*/

void			print_string(void)
{
	int		len;
	char	*(*f)(int, char, char *, int *);

	if (g_flag->ls != NULL)
		print_string_unicode();
	else
	{
		if (!g_flag->s)
			g_flag->s = "(null)";
		len = ft_strlen(g_flag->s);
		if (g_flag->precision < len && g_flag->precision != -1)
			len = g_flag->precision;
		g_flag->s = ft_substr(g_flag->s, 0, len);
		if (g_flag->left == 1)
			f = &print_after;
		else
			f = &print_before;
		if (g_flag->width > len)
			g_flag->s = f(g_flag->width, ' ', g_flag->s, &len);
		ft_putstr_fd(g_flag->s, 1);
		g_flag->total_print += len;
		free(g_flag->s);
	}
}

/*
** Impression des W CHAR *
*/

static void		print_string_unicode2(wchar_t *ls, int len)
{
	if (g_flag->left == 1)
	{
		print_ls(ls, len);
		if ((g_flag->width - len) > 0)
			g_flag->total_print += print_space(g_flag->width - len);
	}
	else
	{
		if ((g_flag->width - len) > 0)
			g_flag->total_print += print_space(g_flag->width - len);
		print_ls(ls, len);
	}
}

void			print_string_unicode(void)
{
	int		i;
	int		len;
	wchar_t *ls;

	ls = g_flag->ls;
	i = 0;
	len = 0;
	while (ls[i])
	{
		len += size_unicode(ls[i]);
		if (g_flag->precision < len && g_flag->precision != -1)
		{
			len -= size_unicode(ls[i]);
			if (len > 0 && g_flag->precision - len > g_flag->width)
				g_flag->width += (g_flag->precision - len);
			break ;
		}
		i++;
	}
	print_string_unicode2(ls, len);
}
