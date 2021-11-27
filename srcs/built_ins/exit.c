/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:37 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/26 17:43:03 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Exit return an error if there the next argument is not a number and set
** error to 2
** Exit return an error if there is too many argument and set the error to 1
*/

static void	exit_error(int error, char *arg) // revoir exit -1 !
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	if (error == 1)
	{
		ft_putstr_fd(S_TOO_MANY_ARGS_CD, STDERR_FILENO); // ne pas stop
		set_exit_status(1, 0);
	}
	else if (error == 2)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(S_NOT_NUM, STDERR_FILENO); // stop dans tous les cas
		set_exit_status(2, 0);
		set_exit_value(1);
	}
}

int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+' || ft_isdigit(str[0]))
		i++;
	else
		return (FALSE);
	if (!ft_isdigit(str[0]) && !ft_isdigit(str[i]))
		return (FALSE);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (FALSE);
	return (TRUE);
}

/*
** Exit stop if there is not argument / a number only or no number and too
** many arguments
*/

void	exec_exit(char **arg, char ***env) // Ctrl + C set a 130 la valeur de retour
{
	(void)env;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (arg[1])
	{
		if (str_isdigit(arg[1]))
		{
			if (arg[2] == NULL)
			{
				set_exit_status(ft_atoi(arg[1]), 0); //variable globale directement et stop
				set_exit_value(1);
			}
			else
				exit_error(1, arg[1]);
		}
		else
			exit_error(2, arg[1]);
	}
	else
		set_exit_value(1);
	// Si 0 arg print et return last return value
	// Si 1 arg chiffre, print et return chiffre
	// Si 1 arg pas chiffre print error arg1: numeric argument required\n return 2
	// Si plus arg 0 chiffre et 1 pas chiffre print et error exit: too many arguements\n mais pas stop et return value 1
	// Si plus arg 0 pas chiffre print arg1: numeric argument required\n stop et return 2
}
