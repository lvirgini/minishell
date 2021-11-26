/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:37:45 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/26 17:37:33 by eassouli         ###   ########.fr       */
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

void	exec_echo(char **arg, char ***env)
{
	int	trail;

	(void)env;
	set_exit_status(0, 0);
	trail = 0;
	if (arg[1] == NULL)
	{
		printf("\n");
		return ;
	}
	else if (ft_strcmp(arg[1], "-n") == 0)
		trail = 1;
	print_echo(arg, 1 + trail);
	if (trail == 0)
		printf("\n");
}
