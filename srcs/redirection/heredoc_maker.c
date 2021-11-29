/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:05 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 17:30:49 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

/*
**  HERE DOC
*/

/*
** recuperation des saisie via readline, expand si besoin et enregistre
**	dans heredoc data.
*/

int	get_line_for_heredoc(t_hdoc *heredoc, char **env)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (g_exit.status == 130)
				return (FAILURE);
			display_heredoc_error(heredoc->delimitor);
			return (SUCCESS);
		}
		if (ft_strcmp(line, heredoc->delimitor) == 0)
		{
			free(line);
			return (SUCCESS);
		}
		if (heredoc->need_expand)
			line = expand_heredoc_line(line, env);
		heredoc->data = ft_list_add_one(heredoc->data, line);
		if (!heredoc->data)
			return (FAILURE);
	}
}

/*
** specially for HEREDOC if a signal has been occured : 
**	Stop heredoc in handle_heredoc signal function : close STDIN_FILENO.
** 	it the only whay
*/

static int	get_back_stdin_when_stop_heredoc(int stdinput)
{
	if (stdinput == -1)
		return (FAILURE);
	if (dup2(stdinput, STDIN_FILENO) != 0)
	{
		perror("dup2 in get_back_stdin_when_stop_heredoc()");
		return (FAILURE);
	}
	close(stdinput);
	return (SUCCESS);
}
/*
**	Mise en place des heredoc ; ceation de la liste des donnes
**	recuperation de la liste par get line for heredoc;
*/

int	make_heredoc(t_hdoc *heredoc, char **env)
{
	int	stdinput;

	signal(SIGINT, handle_heredoc);
	signal(SIGQUIT, SIG_IGN);
	g_exit.status = 0;
	while (heredoc)
	{
		stdinput = dup(STDIN_FILENO);
		if (get_line_for_heredoc(heredoc, env) == FAILURE)
		{
			get_back_stdin_when_stop_heredoc(stdinput);
			return (FAILURE);
		}
		if (get_back_stdin_when_stop_heredoc(stdinput) == FAILURE)
			return (FAILURE);
		heredoc = heredoc->next;
	}
	return (SUCCESS);
}
