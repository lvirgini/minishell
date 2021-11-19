/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:37:45 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/19 16:15:50 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_print(char **arg, int i)
{
	while (arg[i])
	{
		printf("%s", arg[i]);
		if (arg[i + 1] != NULL)
			printf(" ");
		i++;
	}
}

void	exec_echo(char **arg, char **env, t_builtin *builtin)
{
	int	trail;
	
	(void)env;
	(void)builtin;
	trail = 0;
	if (arg[1] == NULL)
	{
		printf("\n");
		return ;
	}
	else if (strcmp(arg[1], "-n") == 0)
		trail = 1;
	echo_print(arg, 1 + trail);
	if (trail == 0)
		printf("\n");
}
