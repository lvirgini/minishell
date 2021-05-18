/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:34:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 11:12:47 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char		*get_input(t_env *env, char *prompt)
{
	char	*input;

	while (true)
	{
		ft_putstr(prompt);
		get_next_line(0, &input);
		if (input)
			return (input);
		free(input);
	}
}



/*
** create the dipslay
*/

int			create_terminal(t_env **env)
{
	char	*prompt;
	char	*input;
	int		ret_cmds;
	t_cmd	cmds;

	prompt = get_prompt_display(*env);
	if (prompt == NULL)
		return (FAILURE);
	ret_cmds = 0;
	input = NULL;
	while (ret_cmds != EXIT)
	{
		input = get_input(*env, prompt);
		printf("input = %s\n", input);
		cmds = parse_input(input);
		free(input);
	}
	free(prompt);
	return (SUCCESS);
}
