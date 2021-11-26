/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:21:39 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 17:30:24 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	static char	*str_cmd[7] = {S_ECHO, S_CD, S_PWD, S_EXPORT, S_UNSET, S_ENV,
		S_EXIT};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(cmd, str_cmd[i]) == 0)
			return (i);
		i++;
	}
	return (NOT_BUILTIN);
}
