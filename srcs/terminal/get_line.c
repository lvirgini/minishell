/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 15:32:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_terminal(void)
{
	char		*line;
	t_prompt	*prompt;

	prompt = get_prompt(NULL, NULL);
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
	}
	free_t_prompt(prompt);
}
