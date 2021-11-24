/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:37 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/24 18:03:24 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_exit(char **arg, char ***env)
{
	(void)env;
	(void)arg;
	//print exit\n set variable globale pour stopper loop
	// Ctrl + D doit ecrire exit
}
