/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:54:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 16:21:00 by lvirgini         ###   ########.fr       */
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
		ft_strlcat(formatted, &(minishell[1]), len);
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
		len -= 1;
	return (len);
}

int	layout_prompt(t_prompt *prompt)
{
	size_t		len;

	if (prompt->need_change == false)
		return (SUCCESS);
	prompt->need_change = false;
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
