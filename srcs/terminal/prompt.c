/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:12:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/04 14:59:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*get_prompt(char *user, char *pwd)
{
	size_t	len;
	char	*prompt;

	if (!user)
		len = ft_strlen(pwd) + PROMPT_SIZE_NO_USER;
	else
		len = ft_strlen(user) + ft_strlen(pwd) + PROMPT_SIZE;
	prompt = (char *)malloc(sizeof(char) * (len + 1));
	if (!prompt)
		return (NULL);
	ft_strlcpy(prompt, S_COLOR_GREEN, 6);
	if (user)
	{
		ft_strlcat(prompt, user, len);
		ft_strlcat(prompt, "@", len);
	}
	ft_strlcat(prompt, "Minishell", len);
	ft_strlcat(prompt, S_COLOR_STD, len);
	ft_strlcat(prompt, ":", len);
	ft_strlcat(prompt, S_COLOR_BLUE, len);
	if (pwd)
		ft_strlcat(prompt, pwd, len);
	ft_strlcat(prompt, S_COLOR_STD, len);
	if (user && ft_strcmp(user, "root") == 0)
		ft_strlcat(prompt, "# ", len);
	else
		ft_strlcat(prompt, "$ ", len);
	return (prompt);
}
/*
void		formatting_prompt(char *prompt, char *user, size_t size_max)
{
	char	pwd[256];
	size_t	len;

	getcwd(pwd, 256);
	len = ft_strlen(user) + ft_strlen(pwd) + PROMPT_FORMATTING_SIZE;
	if (len > size_max)
		len = size_max;
	ft_strlcpy(prompt, STR_COLOR_GREEN, 6);
	if (user)
		ft_strlcat(prompt, user, len);
	ft_strlcat(prompt, "\33[0m:", len);
	ft_strlcat(prompt, STR_COLOR_BLUE, len);
	if (pwd != '\0')
		ft_strlcat(prompt, pwd, len);
	ft_strlcat(prompt, STR_COLOR_STD, len);
	if (user && ft_strcmp(user, "root") == 0)
		ft_strlcat(prompt, "# ", len);
	else
		ft_strlcat(prompt, "$ ", len);
}*/