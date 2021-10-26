/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:11:58 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 15:03:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_this_env(char *env)
{
	if (env)
	{
		ft_putstr(env);
		ft_putstr("\n");
	}
}

void	print_list_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		ft_putstr(env[i]);
		ft_putstr("\n");
		i++;
	}
}
