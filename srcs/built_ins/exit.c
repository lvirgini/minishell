/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:37 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/25 11:40:43 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_exit(char **arg, char ***env)
{
	(void)env;
	(void)arg;
	// Cast chiffre en unsigned char
	// Si 0 arg print et return last return value
	// Si 1 arg chiffre, print et return chiffre
	// Si 1 arg pas chiffre print error arg1: numeric argument required\n return 2
	// Si plus arg 0 chiffre et 1 pas chiffre print et error exit: too many arguements\n mais pas stop et return value 1
	// Si plus arg 0 pas chiffre print arg1: numeric argument required\n stop et return 2
	//print exit\n set variable globale pour stopper loop
	// Ctrl + D doit appeler exit
}
