/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:37:45 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/27 12:36:49 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo(char **arg, int i)
{
	while (arg[i])
	{
		printf("%s", arg[i]);
		if (arg[i + 1] != NULL)
			printf(" ");
		i++;
	}
}

int	is_trail(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && str[i] == 'n')
		i++;
	if (str[i])
		return (0);
	return (1);
}

void	exec_echo(char **arg, char ***env)
{
	int	i;
	int	trail;

	(void)env;
	i = 1;
	trail = 0;
	set_exit_status(0, 0);
	if (arg[i] == NULL)
	{
		printf("\n");
		return ;
	}
	while (arg[i] && is_trail(arg[i]) == 1)
	{
		trail = 1;
		i++;
	}
	print_echo(arg, i);
	if (trail == 0)
		printf("\n");
}
