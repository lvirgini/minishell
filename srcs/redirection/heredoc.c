/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:05 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 14:14:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		line = NULL;
		line = readline("> ");
		if (!line)
		{
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
		if (!line)
			return (FAILURE);
		heredoc->data = ft_list_add_one(heredoc->data, line);
		if (!heredoc->data)
			return (FAILURE);
	}
}

/*
**	Mise en place des heredoc ; ceation de la liste des donnes
**	recuperation de la liste par get line for heredoc;
*/

int	make_heredoc(t_hdoc *heredoc, char **env)
{
	while (heredoc)
	{
		if (get_line_for_heredoc(heredoc, env) == FAILURE)
			return (FAILURE);
		heredoc = heredoc->next;
	}
	return (SUCCESS);
}

/*
** si le heredoc est le dernier ( priorite a 0 car aucun input derriere) 
**	creer le pipe pour ecrire sur la sortie du pipe et dup2 pour aue l'entree 
**	du pipe corresponde bien.
*/

int	setup_heredoc_input(t_hdoc *heredoc)
{
	int		pipefd[2];

	while (heredoc)
	{
		if (heredoc->priority == 0)
		{
			if (pipe(pipefd) == -1)
			{
				perror("pipe in setup_heredoc()");
				return (FAILURE);
			}
			if (dup2(pipefd[IN], IN))
			{
				perror("dup2 in setup_heredo_input()");
				return (FAILURE);
			}
			print_list_fd(heredoc->data, pipefd[OUT]);
			close_fd(pipefd[OUT]);
			return (SUCCESS);
		}
		heredoc = heredoc->next;
	}
	return (SUCCESS);
}