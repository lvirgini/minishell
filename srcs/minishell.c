/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:25:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/26 14:33:20 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	
** MINISHELL by eassouli and lvirgini
*/

void	handle_sigint(int sig)
{
	(void)sig;
	rl_on_new_line();
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int argc, char *argv[], char *env[])
{
	char	**minishell_env;

	(void)argc;
	(void)argv;
	minishell_env = make_minishell_env(env);
	if (!minishell_env)
		return (1);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	make_terminal(&minishell_env);
	free_list(minishell_env);
	return (get_exit_status());
}
