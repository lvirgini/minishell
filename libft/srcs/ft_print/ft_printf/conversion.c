/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:11:30 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/04 21:29:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Convertis le nombre décimal en hexadecimal
** Retourne sous forme char * pour traitement d'impression
*/

char	*convert_hexadecimal(void)
{
	t_ull	i;
	int		len;
	char	*result;
	char	*hexa_base;

	len = 0;
	if (g_flag->specifiers == 'x')
		hexa_base = "0123456789abcdef";
	else
		hexa_base = "0123456789ABCDEF";
	i = g_flag->uarg;
	while ((i /= 16) > 0)
		++len;
	if (!(result = malloc(sizeof(result) * (++len + 1))))
		return (NULL);
	result[len] = '\0';
	if (g_flag->uarg == 0)
		result[0] = '0';
	while (g_flag->uarg)
	{
		result[--len] = hexa_base[g_flag->uarg % 16];
		g_flag->uarg = g_flag->uarg / 16;
	}
	return (result);
}

/*
** Convertis le nombre décimal des adresses en hexadecimal
** Retourne sous forme char * pour traitement d'impression.
*/

char	*convert_adress(char format)
{
	t_ull	i;
	int		len;
	char	*result;
	char	*hexa_base;

	len = 0;
	hexa_base = "0123456789abcdef";
	i = g_flag->uarg;
	while ((i /= 16) > 0)
		++len;
	if (!(result = malloc(sizeof(result) * (++len + 3))))
		return (NULL);
	len += 2;
	result[len] = '\0';
	if (g_flag->uarg == 0 && format != '.' && g_flag->precision != 0)
		result[2] = '0';
	while (g_flag->uarg)
	{
		result[--len] = hexa_base[g_flag->uarg % 16];
		g_flag->uarg = g_flag->uarg / 16;
	}
	result[0] = '0';
	result[1] = 'x';
	return (result);
}
