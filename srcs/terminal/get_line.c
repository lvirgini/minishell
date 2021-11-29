/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 14:29:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_only_space_line(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (true);
	return (false);
}
extern t_return_value	g_exit;

void	make_shell(char *line, char ***env, t_prompt *prompt)
{
	t_token		**token;
	t_cmd		**cmd;

	if (is_only_space_line(line))
		return ;
	token = lexer_minishell(line);
	cmd = parser_minishell(token);
	free_list_token(token);
	if (expanser(cmd, *env) && cmd)
	{
		if (executer(cmd, env) == FAILURE && g_exit.status != 130)
		{
			free_t_prompt(prompt);
			exit_minishell(cmd, *env);
		}
	}
	free_list_cmd(cmd);
}

/*
** get line from std IN
** if line is NULL : it 's Ctrl-D
** if line != \0 :
**		add to history
**		make shell (lexer - parser - expanser - IO setup - exec cmds)
**		update prompt
*/

int	manage_readline(char ***env, t_prompt *prompt)
{
	char		*line;

	line = readline(prompt->formatted);
	if (line)
	{
		if (*line)
		{
			add_history(line);
			make_shell(line, env, prompt);
			if (update_prompt(*env, &prompt) == FAILURE)
				return (FAILURE);
		}
		free(line);
	}
	else
	{
		printf("exit\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

/*
**	while not exited signals or functions read stdin for make shell
** if manage readline failed: a functions somewhere has failed
*/

void	make_terminal(char ***env)
{
	t_prompt	*prompt;

	prompt = initialize_prompt(*env);
	if (!prompt)
		return ;
	while (g_exit.value == 0)
	{
		signal(SIGINT, handle_prompt);
		signal(SIGQUIT, SIG_IGN);
		if (manage_readline(env, prompt) == FAILURE)
			break ;
	}
	free_t_prompt(prompt);
	rl_clear_history();
}
