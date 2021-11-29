/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:54:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 19:25:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** layout a char * for getline prompt : 
**
*/

void	formatted_prompt(char *formatted, char *user, char *cwd, size_t len)
{
	static char	*color_green = GREEN_COLOR;
	static char	*minishell = "@minishell\33[0m:\33[94m";
	static char	*end = "\33[0m$ ";

	ft_strlcpy(formatted, color_green, len);
	if (user && *user)
	{
		ft_strlcat(formatted, user, len);
		ft_strlcat(formatted, minishell, len);
	}
	else
		ft_strlcat(formatted, minishell + 1, len);
	if (cwd)
		ft_strlcat(formatted, cwd, len);
	else
		ft_strlcat(formatted, ".", len);
	ft_strlcat(formatted, end, len);
}

static	size_t	get_prompt_len(t_prompt *prompt)
{
	size_t	len;

	len = PROMPT_LEN;
	if (prompt->cwd)
		len += ft_strlen(prompt->cwd);
	else
		len++;
	if (prompt->user)
	len += ft_strlen(prompt->user);
	else
		len --;
	return (len);
}

int	layout_prompt(t_prompt *prompt)
{
	size_t		len;

	if (prompt->formatted)
		free(prompt->formatted);
	len = get_prompt_len(prompt);
	prompt->formatted = (char *)malloc(sizeof(char) * (len + 1));
	if (prompt->formatted == NULL)
	{
		perror("layout_prompt malloc()");
		return (FAILURE);
	}
	formatted_prompt(prompt->formatted, prompt->user, prompt->cwd, len);
	return (SUCCESS);
}

/*
** getcwd : in this way returns a malloc char *
*/

int	update_prompt(char **env, t_prompt **prompt)
{	
	int	need_free;

	need_free = 0;
	(*prompt)->user = get_env_value(env, "USER");
	(*prompt)->cwd = get_env_value(env, "PWD");
	if ((*prompt)->cwd == NULL)
	{
		(*prompt)->cwd = getcwd(NULL, 0);
		need_free = 1;
	}	
	if (layout_prompt(*prompt) == FAILURE)
	{
		free_t_prompt(*prompt);
		return (FAILURE);
	}
	if (need_free == 1 && (*prompt)->cwd != NULL)
	{
		free((*prompt)->cwd);
		(*prompt)->cwd = NULL;
	}	
	return (SUCCESS);
}
