/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:28:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/11 12:27:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Impression des CHAR et WCHAR
*/

int		print_character(void)
{
	int				nb_oct;
	char			s[g_flag->width];

	nb_oct = 1;
	g_flag->total_print += 1;
	if (g_flag->width >= nb_oct)
	{
		g_flag->width -= nb_oct;
		g_flag->total_print += g_flag->width;
		ft_memset((char *)s, ' ', g_flag->width);
	}
	if (g_flag->left == 1)
	{
		write(1, &(g_flag->uarg), 1);
		if (g_flag->width >= nb_oct)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
	}
	else
	{
		if (g_flag->width >= nb_oct)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
		write(1, &(g_flag->uarg), 1);
	}
	return (0);
}

int		print_wchar(int nb_oct)
{
	char			s[g_flag->width];

	if (g_flag->width >= nb_oct)
	{
		g_flag->width -= nb_oct;
		g_flag->total_print += g_flag->width;
		ft_memset((char *)s, ' ', g_flag->width);
	}
	if (g_flag->left == 1)
	{
		print_unicode(g_flag->uarg, nb_oct);
		if (g_flag->width > nb_oct)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
	}
	else
	{
		if (g_flag->width >= nb_oct)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
		print_unicode(g_flag->uarg, nb_oct);
	}
	return (0);
}

/*
** Si pas de flg mais un %
*/

void	print_percent(void)
{
	char			s[g_flag->width];

	g_flag->total_print += 1;
	if (g_flag->width >= 1)
	{
		g_flag->width -= 1;
		g_flag->total_print += g_flag->width;
		if ((g_flag->zero == 1) && g_flag->left == 0)
			ft_memset((char *)s, '0', g_flag->width);
		else
			ft_memset((char *)s, ' ', g_flag->width);
	}
	if (g_flag->left == 1)
	{
		write(1, &(g_flag->uarg), 1);
		if (g_flag->width >= 1)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
	}
	else
	{
		if (g_flag->width >= 1)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
		write(1, &(g_flag->uarg), 1);
	}
}
