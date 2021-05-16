/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:13:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/16 18:00:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_working_directory(void)
{
	char	*cwd;
	
	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
	{
		//check env PWD
		cwd = (char *)malloc(sizeof(char) * BUFFER_MAX);
		if (cwd == NULL)
		{
			perror(ERR_MALLOC);
			return(NULL);
		}
		cwd = getenv("PWD");
		if (!*cwd)
		{
			free(cwd);
			return (NULL);
		}
	}
	return (cwd);
}

void			formatting_prompt(char *prompt, char *user, char *pwd, size_t len)
{
	ft_strlcpy(prompt, STR_COLOR_GREEN, 6);
	ft_strlcat(prompt, user, len);
	ft_strlcat(prompt, "\33[0m:", len);
	ft_strlcat(prompt, STR_COLOR_BLUE, len);
	ft_strlcat(prompt, pwd, len);
	ft_strlcat(prompt, STR_COLOR_STD, len);
	if (ft_strcmp(user, "root") == 0)
		ft_strlcat(prompt, "# ", len);
	else
		ft_strlcat(prompt, "$ ", len);
}


char			*get_prompt_display(t_env *env)
{
	char	*user;
	char	*pwd;
	char	*prompt;
	int		total_len;

	user = get_value_t_env(env, "USER");
	pwd = get_value_t_env(env, "PWD");
	total_len = ft_strlen(user) + ft_strlen(pwd) + PROMPT_FORMATTING_SIZE;
	prompt = (char *)malloc(sizeof(char) * total_len);
	if (prompt == NULL)
	{
		perror(ERR_MALLOC);
		return (NULL);
	}
	formatting_prompt(prompt, user, pwd, total_len);
	return(prompt);
}

/*
** create the dipslay
*/

int			create_terminal(t_env **env)
{
	char	*prompt;
	char	*input;
	int		ret_cmds;

	input = NULL;
	prompt = get_prompt_display(*env);
	if (prompt == NULL)
		return (FAILURE);
	while (true)
	{
		ft_putstr(prompt);
		get_next_line(0, &input);
		if (input)
		{
			ret_cmds = command_split(input);
			if (ret_cmds == FAILURE || ret_cmds == EXIT)
			{
				free(input);
				return (ret_cmds);
			}
		}
		free(input);
	}
	free(prompt);
	return (SUCCESS);
}
