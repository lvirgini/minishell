/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:05 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 12:44:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  HERE DOC
**
	Dans le parsing -> Si parse input et herdoc : heredoc->type ++

** expansion du here doc :
		si word a des quotes : expansion du word uniauement 
** ERROR : si << eof et ctrl D : 
**  bash: warning: here-document at line 5 delimited by end-of-file (wanted `eof')
**
**  lvirgini@e2r3p8:~/42/minishell$ << eof cat
> bash: warning: here-document at line 5 delimited by end-of-file (wanted `eof')
lvirgini@e2r3p8:~/42/minishell$ << eof cat
> bash: warning: here-document at line 6 delimited by end-of-file (wanted `eof')
lvirgini@e2r3p8:~/42/minishell$ << eof cat
> bash: warning: here-document at line 7 delimited by end-of-file (wanted `eof')
lvirgini@e2r3p8:~/42/minishell$ << eof cat
> bash: warning: here-document at line 8 delimited by end-of-file (wanted `eof')
**
**e2r3p8% bash
lvirgini@e2r3p8:~/42/minishell$ << eof cat
> bash: warning: here-document at line 1 delimited by end-of-file (wanted `eof')
lvirgini@e2r3p8:~/42/minishell$ 
lvirgini@e2r3p8:~/42/minishell$ 
lvirgini@e2r3p8:~/42/minishell$ 
lvirgini@e2r3p8:~/42/minishell$ << eof cat
> bash: warning: here-document at line 5 delimited by end-of-file (wanted `eof')
**

			char **env, t_redir heredoc, 
**  line = readine()

** si line est vide = une ligne vide
** si line
		si line == delimitor   (expand apres la comparaison )
			FIN
		si herdoc est expand
			expand line;
		add line in heredoc
	continue
**
*/

static t_expansion	*expand_only_dollar(char *s, char **env)
{
	size_t	i;
	t_expansion	*expansion;
	t_expansion	*first;

	i = 0;
	first = NULL;
	while (s[i])
	{
		if (s[i] == CHAR_DOLLAR && (i == 0 || s[i - 1] != BACKSLASH))
		{
			expansion = expand_dollar(s + i, env, false);
			if (!expansion)
			{
				free_list_expansion(first);
				return (NULL);
			}
			expansion->start_of_the_expand = i;
			i += expansion->size_to_remove;
			first = add_back_expansion(first, expansion);
		}
		else
			i++;
	}
	return (first);
}

static t_bool	is_dollar_expansion(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == CHAR_DOLLAR && (i == 0 || s[i - 1] != BACKSLASH))
			return (true);
		i++;
	}
	return (false);
}

/*
** expand la ligne du heredoc.
*/

char	*expand_line(char *line, char **env)
{
	t_expansion	*expansion;
	char		*result;

	if (is_dollar_expansion(line))
	{
		expansion = expand_only_dollar(line, env);
		if (!expansion)
			return (FAILURE);
		result = fusion_str_expansion(line, expansion);
		free_list_expansion(expansion);
		free(line);
		return (result);
	}
	return (line);
}

/*
** recuperation des saisie via readline, expand si besoin et enregistre dans heredoc data.
*/

char    **ft_list_add_one2(char **list, char *to_add)
{
  char **result;
	size_t  list_len;

	list_len = listlen(list) + 1;
	result = malloc_list(list_len);
	if (!result)
	{
		free_list(list);
		free(to_add);
		return (NULL);
	}
	list_move(result, list);
	result[list_len - 1] = ft_strdup(to_add);
	if (!result[list_len - 1])
	{
		free_list(result);
		free(result);
		return (NULL);
	}
	result[list_len] = NULL;
	free(list);
	free(to_add);
	return (result);
}

int	get_line_for_heredoc(t_hdoc *heredoc, char **env)
{
	char 	*line;
	int		need_expand;

	need_expand = heredoc->need_expand;
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
		if (need_expand)
			line = expand_line(line, env);
		if (!line)
			return (FAILURE);
		heredoc->data = ft_list_add_one2(heredoc->data, line);
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
		/*heredoc->data = malloc_list(1);
		if (!heredoc->data)
			return (FAILURE);*/
		if (get_line_for_heredoc(heredoc, env) == FAILURE)
			return (FAILURE);
		heredoc = heredoc->next;
	}
	return (SUCCESS);
}

/*
** si le heredoc est le dernier ( priorite a 0 car aucun input derriere) 
**	creer le pipe pour ecrire sur la sortie du pipe et dup2 pour aue l'entree du pipe corresponde bien.
*/

int	setup_heredoc_input(t_hdoc *heredoc)
{
	int pipefd[2];

	while (heredoc)
	{
		if (heredoc->priority == 0)
		{
		//	printf("delimitor = %s\n priority = %d\n", heredoc->delimitor, heredoc->priority);
		//	print_list(heredoc->data);
			if (pipe(pipefd) == -1)
			{
				perror("pipe in setup_heredoc()");
				return (FAILURE);
			}	
			if (dup2(pipefd[IN],IN))
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
