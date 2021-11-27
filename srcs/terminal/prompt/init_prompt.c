/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:58:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 16:39:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Malloc un new prompt empty
*/

t_prompt	*malloc_prompt(void)
{
	t_prompt	*prompt;

	prompt = (t_prompt *)malloc(sizeof(t_prompt));
	if (!prompt)
	{
		perror("malloc init_prompt())");
		return (NULL);
	}
	ft_memset(prompt, 0, sizeof(t_prompt));
	return (prompt);
}

/*
** Free all inside the t_prompt
*/

void	free_t_prompt(t_prompt *prompt)
{
	if (prompt)
	{	
		if (prompt->formatted)
			free(prompt->formatted);
		free(prompt);
	}	
}

char	*get_prompt_cwd(void)
{
	return (getcwd(NULL, 0));
}

/*
** Init prompt with user defined in env and cwd by getcwd functions
*/

t_prompt	*initialize_prompt(char **env)
{
	t_prompt	*prompt;

	prompt = malloc_prompt();
	if (!prompt)
		return (NULL);
	prompt->cwd = get_env_value(env, "PWD");
	prompt->user = get_env_value(env, "USER");
	if (layout_prompt(prompt) == FAILURE)
	{
		free_t_prompt(prompt);
		return (NULL);
	}
	return (prompt);
}
