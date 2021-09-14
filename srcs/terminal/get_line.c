/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/14 15:23:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_terminal(void)
{
	char	*line;
	char	prompt[256];

	formatting_prompt(prompt, "lvirgini", 256);
	while (1)
	{
		line = readline(prompt);
		if (line)
		{
			if(*line)
				add_history(line);
			free(line);
		}
		else
			printf("\n");
	}
}
