/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:12:56 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/26 17:36:06 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Call function with exit_status to change value
** Or call with -1 to get the value
*/

unsigned char	set_exit_status(int exit_status, int get)
{
	static unsigned char	value = 0;

	if (get == 1)
		return (value);
	else
		value = (unsigned char)exit_status;
	return (value);
}

/*
** Call function with exit_value to change value to 1 to exit
** Or call with -1 to get the value
*/

unsigned char	set_exit_value(int exit_value)
{
	static unsigned char	value = 0;

	if (exit_value == -1)
		return (value);
	else
		value = 1;
	return (value);
}

unsigned char	get_exit_status(void)
{
	return (set_exit_status(0, 1));
}

unsigned char	get_exit_value(void)
{
	return (set_exit_value(-1));
}
