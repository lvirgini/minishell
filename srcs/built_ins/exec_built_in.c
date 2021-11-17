/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:37:21 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/15 18:38:33 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_built_in(char **env, t_cmd *cmd, t_bi *bi)
{
	(void)env;
	(void)cmd;
	(void)bi;
	printf("%s\n", bi->words[bi->cmd]);
	return (SUCCESS);
}