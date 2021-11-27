/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:48:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 19:49:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_str(char *str)
{
	if (str)
	{
		ft_putstr(str);
		ft_putstr("\n");
	}
}

void	print_list(char **list)
{
	int	i;

	i = 0;
	while (list && list[i])
	{
		ft_putstr(list[i]);
		ft_putstr("\n");
		i++;
	}
}

void	print_list_fd(char **list, int fd)
{
	int	i;

	i = 0;
	while (list && list[i])
	{
		ft_putstr_fd(list[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
}
