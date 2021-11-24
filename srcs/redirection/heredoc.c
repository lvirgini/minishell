/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:05 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 17:34:43 by lvirgini         ###   ########.fr       */
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


int	make_heredoc(t_hdoc *heredoc)
{
	while (heredoc)
	{
		printf("delimitor = %s\n priority = %d\n", heredoc->delimitor, heredoc->priority);
		heredoc = heredoc->next;
	}
	return (SUCCESS);
}

