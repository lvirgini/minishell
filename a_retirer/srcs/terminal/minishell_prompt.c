/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:48:23 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 10:35:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Formatting prompt on green(USER):blue(PWD)
** only estetic
*/

static void		formatting_prompt(char *prompt, char *user, char *pwd,
				size_t len)
{
	ft_strlcpy(prompt, STR_COLOR_GREEN, 6);
	if (user)
		ft_strlcat(prompt, user, len);
	ft_strlcat(prompt, "\33[0m:", len);
	ft_strlcat(prompt, STR_COLOR_BLUE, len);
	if (pwd)
		ft_strlcat(prompt, pwd, len);
	ft_strlcat(prompt, STR_COLOR_STD, len);
	if (user && ft_strcmp(user, "root") == 0)
		ft_strlcat(prompt, "# ", len);
	else
		ft_strlcat(prompt, "$ ", len);
}

/*
** get information needed for prompt (user and pwd variable env)
*/

char			*get_default_prompt(t_env *env)
{
	char	*user;
	char	*pwd;
	char	*prompt;
	int		total_len;

	user = get_value_t_env(env, "USER");
	pwd = get_value_t_env(env, "PWD");
	total_len = ft_strlen(user) + ft_strlen(pwd)
		+ PROMPT_FORMATTING_SIZE;
	prompt = (char *)malloc(sizeof(char) * total_len);
	if (prompt == NULL)
	{
		perror(ERR_MALLOC);
		return (NULL);
	}
	formatting_prompt(prompt, user, pwd, total_len);
	return (prompt);
}

char			*get_prompt_display(t_env *env)
{
/*	char	*ps1;

	ps1 = get_value_t_env(env, "PS1");
	if (ps1 != NULL)
		return (get_personal_prompt(ps1));*/
	return (get_default_prompt(env));
}
