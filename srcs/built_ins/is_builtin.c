/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:21:39 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/17 15:45:47 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd, t_builtin *bi)
{
	init_builtin(bi); // deplacer
	reset_builtin(bi);
	if (ft_strncmp(cmd, S_ECHO, 4) == 0 && ft_strlen(cmd) == 4)
		bi->cmd = CMD_ECHO;
	else if (ft_strncmp(cmd, S_CD, 2) == 0 && ft_strlen(cmd) == 2)
		bi->cmd = CMD_CD;
	else if (ft_strncmp(cmd, S_PWD, 3) == 0 && ft_strlen(cmd) == 3)
		bi->cmd = CMD_PWD;
	else if (ft_strncmp(cmd, S_EXPORT, 6) == 0 && ft_strlen(cmd) == 6)
		bi->cmd = CMD_EXPORT;
	else if (ft_strncmp(cmd, S_UNSET, 5) == 0 && ft_strlen(cmd) == 5)
		bi->cmd = CMD_UNSET;
	else if (ft_strncmp(cmd, S_ENV, 3) == 0 && ft_strlen(cmd) == 3)
		bi->cmd = CMD_ENV;
	else if (ft_strncmp(cmd, S_EXIT, 4) == 0 && ft_strlen(cmd) == 4)
		bi->cmd = CMD_EXIT;
	if (bi->cmd != -1)
		return (SUCCESS);
	return (FAILURE);
}
