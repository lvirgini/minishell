/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:44:50 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/29 13:29:57 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

/*
** How to handle main prompt
** Ctrl + C must print the actual prompt with a new empty line
** Ctrl + \ must do nothing
** Ctrl + D must exit the program
*/

void	handle_prompt(int sig)
{
	(void)sig;
	g_exit.status = 130;
	rl_on_new_line();
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

/*
** How to handle commands
** Ctrl + C must print a new_empty line and stop the actual cmd like cat
** Ctrl + \ must stop the process and print Quit with the prompt
** Ctrl + D must stop the process and print the prompt on the same line
*/

void	handle_cmd(int sig)
{
	if (sig == SIGINT)
	{
		g_exit.status = 130;
		printf("\n");
	}
	else if (sig == SIGQUIT)
	{
		g_exit.status = 131;
		ft_putstr_fd("Quit\n", 2);
	}
}

/*
** How to handle heredoc
** Ctrl + C must stop the heredoc and get back to the main prompt
** Ctrl + \ must do nothing
** Ctrl + D must print an error and get back to the main prompt
*/

void	handle_heredoc(int sig)
{
	(void)sig;
	g_exit.status = 130;
	close(0);
	printf("\n");
}
