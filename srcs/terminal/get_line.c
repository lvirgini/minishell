/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/07 14:54:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** premier appel : get_prompt va creer t_prompt via l'environnement récuperé
*/

int	make_terminal(t_env **env)
{
	char		*line;
	t_prompt	*prompt;

	prompt = get_prompt(env, NULL);
	while (1)
	{
		line = readline(prompt->formatted);
		if (line)
		{
			if(*line)
				add_history(line);
			free(line);
		}
		else
			printf("\n");
		printf("line = %s\n", line);
		edit_or_add_t_env(env, "USER", line);
		prompt = get_prompt(env, prompt);
	}
	free_t_prompt(prompt);
}
