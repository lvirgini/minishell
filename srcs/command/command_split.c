/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:00:23 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/16 18:19:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_cmds(char *cmd)
{
	printf("commande %s\n", cmd);
	return (SUCCESS);
}

//////// NOPE
int		command_split(char *input)
{
	char 	**cmds;
	int		i;
	int		ret;

	cmds = ft_split(input, ';');
	if (cmds == NULL)
	{
		perror(ERR_MALLOC);
		return(FAILURE);
	}
	i = 0;
	while (cmds[i])
	{
		ret = check_cmds(cmds[i]);
		if (ret == FAILURE)
			display_command_error(cmds[i], NOT_FOUND);
		else if (ret == EXIT)
		{
			free(cmds);
			return (EXIT);
		}
		i++;
	}
	free(cmds);
	return(SUCCESS);
}