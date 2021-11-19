/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:21:39 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/19 16:11:33 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd, t_builtin *builtin)
{
	static char	*str_cmd[7] = {S_ECHO, S_CD, S_PWD, S_EXPORT, S_UNSET, S_ENV,
		S_EXIT};
	int			i;

	init_builtin(builtin); // deplacer
	reset_builtin(builtin);
	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(cmd, str_cmd[i]) == 0)
			builtin->cmd = i;
		i++;
	}
	if (builtin->cmd != -1)
		return (SUCCESS);
	return (FAILURE);
}
