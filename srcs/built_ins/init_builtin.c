/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:39:52 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/20 17:14:23 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_builtin(t_builtin *builtin)
{
	if (builtin->home == NULL)
		builtin->home = get_home_dir(); // si nul
}

void	reset_builtin(t_builtin *builtin)
{
	builtin->cmd = -1;
	builtin->error = -1;
}
