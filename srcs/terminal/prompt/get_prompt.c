/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:12:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 16:16:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check for update prompt
**		if $USER is not same as prompt->user
**		if working directory is not same as prompt->cwd
**	return : true if prompt->formatted for getline must be updated.
*/

t_bool	need_change_user(char *old_user, char *actual_user)
{
	if (!actual_user)
	{
		if (!old_user)
			return (false);
		return (true);
	}
	if (!old_user || ft_strcmp(old_user, actual_user))
		return (true);
	return (false);
}

t_bool	need_change_cwd(char *old_cwd, char *actual_cwd)
{
	if (!actual_cwd)
	{
		if (!old_cwd)
			return (false);
		return (true);
	}
	if (!old_cwd || ft_strcmp(old_cwd, actual_cwd))
		return (true);
	return (false);
}

t_bool	change_prompt_user(t_prompt *prompt, char *actual_user)
{
	if (prompt->user)
		free(prompt->user);
	prompt->user = NULL;
	if (actual_user)
	{
		prompt->user = ft_strdup(actual_user);
		if (!prompt->user)
		{
			perror("malloc change_prompt_user())");
			return (FAILURE);
		}
	}
	prompt->need_change = true;
	return (SUCCESS);
}

static void	change_prompt_cwd(t_prompt *prompt, char *actual_cwd)
{
	free(prompt->cwd);
	prompt->cwd = actual_cwd;
	prompt->need_change = true;
}

/*
** getcwd : in this way returns a malloc char *
*/

int	update_prompt(char **env, t_prompt **prompt)
{	
	char		*user;
	char		*cwd;

	user = get_env_value(env, "USER");
	if (need_change_user((*prompt)->user, user)
		&& !change_prompt_user(*prompt, user))
	{
		free_t_prompt(*prompt);
		return (FAILURE);
	}
	cwd = getcwd(NULL, 0);
	if (need_change_cwd((*prompt)->cwd, cwd))
		change_prompt_cwd(*prompt, cwd);
	else if (cwd)
		free(cwd);
	if (layout_prompt(*prompt) == FAILURE)
	{
		free_t_prompt(*prompt);
		return (FAILURE);
	}
	return (SUCCESS);
}
