/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:05 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 19:53:53 by lvirgini         ###   ########.fr       */
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

char	*expand_line(char *line, char **env)
{
	t_expansion	*expansion;
	char		*result;

	if (need_expand(line))
	{
		expansion = expand_str(line, env);
		if (!expansion)
			return (FAILURE);
		result = fusion_str_expansion(line, expansion);
		free_list_expansion(expansion);
		free(line);
		return (result);
	}
	return (line);
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
			return (SUCCESS);
		if (need_expand)
		{
			line = expand_line(line, env);
			heredoc->data = ft_list_add_one(heredoc->data, line);
			if (!line)
				return (FAILURE);
		}
	}
}

int	make_heredoc(t_hdoc *heredoc, char **env)
{
	//while (heredoc)
//	{
		heredoc->data = malloc_list(0);
		if (get_line_for_heredoc(heredoc, env) == FAILURE)
			return (FAILURE);
		//heredoc = heredoc->next;
	//}


	int pipefd[2];

	printf("delimitor = %s\n priority = %d\n", heredoc->delimitor, heredoc->priority);
	print_list(heredoc->data);
	if (pipe(pipefd) == -1)
		return (FAILURE);
	dup2(pipefd[IN],IN);
	
	print_list_fd(heredoc->data, pipefd[OUT]);
	//heredoc->data = malloc_list(0);
	//ft_putstr_fd("test\ntest\n", pipefd[OUT]);
	close (pipefd[OUT]);
	
/*	while (heredoc)
	{
		heredoc = heredoc->next;
	}*/

	return (SUCCESS);
}

