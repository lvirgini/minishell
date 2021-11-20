/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 19:54:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*

SI "" puis dollar : prend aussi les espace
{
	dqutes dollar = literal value
	// Unquoted implicit null arguments, resulting from the expansion of
	 parameters that have no values, are removed.
}

SI dollar : escape space
MAIS SI il y a des chaine null "" ou '' elles sont supprimée 

mini@debian:~$ export TEST=-d''""test
mini@debian:~$ echo $TEST 
-dtest


int	expand_redirection(t_redir *redir)
{
	while (redir)
	{
		if (!expand(redir->filename))
			return (FAILURE);
		redir = redir->next;
	}
	return (SUCCESS);
}*/

int	word_expand_len(char *str)
{
	return (ft_strlen_set(str, STR_ESCAPE));
}

//OLD
/*
char	*fusion_expand(char *str, int index, char **expansion)
{
	char	*fusion;
	int		size_word_expand;
	int		size_fusion;
	int		size_expansion;

	size_word_expand = word_expand_len(str + index);
	size_expansion = ft_strlen(*expansion);
	size_fusion = ft_strlen(str) - size_word_expand + size_expansion;
	fusion = (char *)malloc(sizeof(char) * size_fusion + 1);
	if (!fusion)
	{
		free(str);
		return (NULL);
	}
	ft_strncpy(fusion, str, index);
	ft_strncpy(fusion + index, *expansion, size_expansion);
	ft_strncpy(fusion + index + size_expansion, str + index + size_word_expand, size_fusion);
	return (fusion);
}*/
int	expanser(t_cmd **list_cmd, char **env)
{
	t_cmd	*cmd;

	if (!list_cmd)
		return (FAILURE);
	cmd = *list_cmd;
	while (cmd)
	{
	//	if (need_expand(cmd->argv))
		if (cmd->argv)
		{
			cmd->argv = expand_argv(cmd->argv, env);
			if (!cmd->argv)
				return (FAILURE);
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}
