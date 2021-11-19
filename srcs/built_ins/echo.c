/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:37:45 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/19 13:24:48 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_echo(char **arg, char **env, t_builtin *bi)
{
	int	trail;
	int	i;
	(void)env;
	(void)bi;

	trail = 0;
	i = 1;
	if (arg[1] == NULL)
	{
		printf("\n");
		return ;
	}
	else if (arg[i] && strcmp(arg[i++], "-n") == 0)
		trail = 1;
	while (arg[i])
	{
		printf("%s", arg[i]);
		if (arg[i + 1] != NULL)
			printf(" ");
		i++;
	}
}
