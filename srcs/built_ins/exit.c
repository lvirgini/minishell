/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:37 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/29 16:42:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

/*
** Exit return an error if there the next argument is not a number and set
** error to 2
** Exit return an error if there is too many argument and set the error to 1
*/

static void	exit_error(int error, char *arg)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	if (error == 1)
	{
		ft_putstr_fd(S_TOO_MANY_ARGS_CD, STDERR_FILENO);
		g_exit.status = 1;
	}
	else if (error == 2)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(S_NOT_NUM, STDERR_FILENO);
		g_exit.status = 2;
		g_exit.value = 1;
	}
}

int	str_isdigit(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (FALSE);
	while (str[i] == '0')
		i++;
	while (str[i + j] && ft_isdigit(str[i + j]))
		j++;
	if (str[i + j] || j > 19)
		return (FALSE);
	return (TRUE);
}

/*
** Exit stop if there is not argument / a number only or no number and too
** many arguments
*/

void	exec_exit(char **arg, char ***env)
{
	(void)env;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (arg[1])
	{
		if (str_isdigit(arg[1]))
		{
			if (arg[2] == NULL)
			{
				g_exit.status = ft_atoll(arg[1]);
				g_exit.value = 1;
			}
			else
				exit_error(1, arg[1]);
		}
		else
			exit_error(2, arg[1]);
	}
	else
		g_exit.value = 1;
}
