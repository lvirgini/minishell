/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:39:52 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/17 16:31:28 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_builtin(t_builtin *bi)
{
	if (bi->home == NULL)
	{
		bi->home = get_home_dir(); // si nul
	}
}

void	reset_builtin(t_builtin *bi)
{
	bi->cmd = -1;
	bi->error = -1;
}
