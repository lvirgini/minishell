/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_absolute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:23:14 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 13:36:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** duplicate absolute path on cmd->path.
*/

t_bool	add_absolute_path(t_cmd *cmd, char *argv)
{
	if (access(argv, F_OK) == 0)
	{
		cmd->path = ft_strdup(argv);
		if (!cmd->path)
		{
			perror("malloc in add_absolute_path");
			return (FAILURE);
		}
		return (SUCCESS);
	}
	display_error(ERR_ABSOLUTE_PATH_NOT_FOUND, argv);
	return (FAILURE);
}
