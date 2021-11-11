/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:12:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/10 16:58:42 by lvirgini         ###   ########.fr       */
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
	static char	*color_green = "\33[32m";
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
		return ; //
	}
	ft_strlcpy(prompt->formatted, color_green, len);
	if (prompt->user && *prompt->user) //
	{
		ft_strlcat(prompt->formatted, prompt->user, len);
		ft_strlcat(prompt->formatted, minishell, len);
	}
	else
		ft_strlcat(prompt->formatted, &(minishell[1]), len);
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
	if (!actual_user || !prompt->user
		|| ft_strcmp(prompt->user, actual_user) != 0)
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

t_prompt	*get_prompt(char **env, t_prompt *prompt)
{	
	char	*user;
	char	*cwd;
	t_bool	need_change;

	user = get_env_value(env, "USER");
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
