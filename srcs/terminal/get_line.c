/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/04 15:00:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_terminal(void)
{
	char	*line;
	char	*prompt;
	char	pwd[256];

	getcwd(pwd, 256);
	prompt = get_prompt("lvirgini", pwd);
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
	free(prompt);
}
