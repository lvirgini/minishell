/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_relative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:28:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 16:20:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	add_relative_path(t_cmd *cmd, char *argv)
{
	int	fd;

	fd = open(cmd->argv[0], __O_DIRECTORY);
	if (fd != -1)
	{	
		close(fd);
		display_error(ERR_IS_A_DIRECTORY, argv);
		return (FAILURE);
	}
	return (add_absolute_path(cmd, argv));
}
