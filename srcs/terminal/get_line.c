/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/15 13:09:42 by lvirgini         ###   ########.fr       */
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
	//char 		*result;

	prompt = get_prompt(env, NULL);
	while (1)
	{
		line = NULL;
		line = readline(prompt->formatted);
		if (line)
		{
			if(*line)
				add_history(line);
	/*		for (int i = 0; line[i]; i++)
				write(1, line + i, 1);
			write (1, "\n", 1);
			for (int i = 0; line[i]; i++)
				printf("%d ", line[i]);
			printf("\n");
			for (int i = 0; line[i]; i++)
				printf("%c ", line[i]);
			printf("\n");	
		printf("|%s|\n", line);
		result =  convert_double_quote(line);
		printf("|%s|\n", result);
		for (int i = 0; result[i]; i++)
			printf("%d ", result[i]);*/


		//printf("line = %s\n", line);
		//edit_or_add_t_env(env, "USER", line);
		prompt = get_prompt(env, prompt);
		free(line);
		}
		else
			printf("\n");


	}
	free_t_prompt(prompt);
}
