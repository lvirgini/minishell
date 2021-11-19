/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/19 17:00:54 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** il faut trouver un bon nom pour cette fonction...
*/

void	make_shell(char *line, char **env, t_builtin *builtin)
{
	t_token		**token;
	t_cmd		**cmd;

	token = lexer_minishell(line);
	cmd = parser_minishell(token);
	free_list_token(token);
	if (expanser(cmd, env) && cmd)
	{
		if (executer(cmd, env, builtin) == FAILURE)
			exit_minishell(cmd, env);
	}
	free_list_cmd(cmd);
}

/*
** premier appel : get_prompt va creer t_prompt via l'environnement récuperé
** while 1 -> pour le moment pas d'arret // voir les signaux
** readline renvoi la ligne saisie
** si la ligne n'est pas vide on la rajoute a l'historique (cmd de readline)
*/

int	make_terminal(char **env)
{
	char		*line;
	t_prompt	*prompt;
	t_builtin	builtin;

	prompt = get_prompt(env, NULL);
	builtin = (t_builtin){-1, -1, -1, NULL, NULL};
	while (1)
	{
		line = NULL;
		line = readline(prompt->formatted);
		if (line)
		{
			if (*line)
			{
				add_history(line);
				make_shell(line, env, &builtin);
			}
			prompt = get_prompt(env, prompt);
			free(line);
		}
		else
			printf("\n");
	}
	free_t_prompt(prompt);
}
