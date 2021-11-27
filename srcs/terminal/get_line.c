/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 18:01:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_shell(char *line, char ***env, t_prompt *prompt)
{
	t_token		**token;
	t_cmd		**cmd;

	token = lexer_minishell(line);
	cmd = parser_minishell(token);
	free_list_token(token);
	if (expanser(cmd, *env) && cmd)
	{
		if (executer(cmd, env) == FAILURE)
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
		signal(SIGINT, handle_prompt); // heredoc stop readline
		// putstr("signal fail");
		// exit(1);
		signal(SIGQUIT, SIG_IGN); // ignore pour heredoc aussi
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
	while (get_exit_value() == 0)
	{
		if (manage_readline(env, prompt) == FAILURE)
			break ;
	}
	free_t_prompt(prompt);
	rl_clear_history();
}
