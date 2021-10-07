/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:12:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/07 14:22:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** layout a char * for getline prompt : 
**
*/

static	size_t	get_prompt_len(t_prompt *prompt)
{
	size_t	len;

	len = ft_strlen(prompt->user) + ft_strlen(prompt->cwd)
		+ 34;
	if (!prompt->user)
		len -= 1;
	return (len);
}

void	layout_prompt(t_prompt *prompt)
{
	static char *color_green = "\33[32m";
	static char	*minishell = "@minishell\33[0m:\33[94m";
	static char	*end = "\33[0m$ ";
	size_t		len;

	len = get_prompt_len(prompt);
	if (prompt->formatted)
		free(prompt->formatted);
	prompt->formatted = (char *)malloc(sizeof(char) * len);
	if (prompt->formatted == NULL)
	{
		perror("layout_prompt malloc()");
		return ;//
	}
	ft_strlcpy(prompt->formatted, color_green, len);
	printf("prompt->user = %s\n", prompt->user);
	if (prompt->user)
	{
		ft_strlcat(prompt->formatted, prompt->user, len);
		ft_strlcat(prompt->formatted, minishell, len);
	}
	else
		ft_strlcat(prompt->formatted, minishell + 1, len);
	ft_strlcat(prompt->formatted, prompt->cwd, len);
	ft_strlcat(prompt->formatted, end, len);
}

/*
** check for update prompt
**		if $USER is not same as prompt->user
**		if working directory is not same as prompt->cwd
**	return : true if prompt->formatted for getline must be updated.
*/

static	int	check_prompt_update(t_prompt *prompt, char *actual_cwd,
	char *actual_user)
{
	t_bool	need_change;

	need_change = false;
	if (!actual_cwd || ft_strcmp(prompt->cwd, actual_cwd) != 0)
	{
		free(prompt->cwd);
		prompt->cwd = ft_strdup(actual_cwd);
		if (!prompt->cwd)
			perror("check prompt update (user)");
		need_change = true;
	}
	if (!actual_user || !prompt->user || ft_strcmp(prompt->user, actual_user) != 0)
	{
		free(prompt->user);
		prompt->user = ft_strdup(actual_user);
		if (!prompt->user && actual_user)
			perror("check prompt update (user)");
		need_change = true;
	}

	return (need_change);
}
/*
** getcwd : in this way returns a malloc char *
*/

t_prompt	*get_prompt(t_env **env, t_prompt *prompt)
{	
	char	*user;
	char	*cwd;
	t_bool	need_change;

	user = get_value_t_env(env, "USER");
	printf("actual user = %s\n", user);
	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (!prompt)
		prompt = init_prompt(user, cwd);
	else
	{
		need_change = check_prompt_update(prompt, cwd, user);
		if (need_change == true)
			layout_prompt(prompt);
	}
	if (cwd)
		free(cwd);
	return (prompt);
}


/*
char	*get_prompt(t_env *env);
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
}*/
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