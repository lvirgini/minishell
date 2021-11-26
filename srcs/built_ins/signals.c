/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:44:50 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/26 16:55:58 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 
*/

void	handle_prompt(int sig)
{
	(void)sig;
	rl_on_new_line();
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

/*
** 
*/

void	handle_cmd(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		printf("\n");
		rl_replace_line("", 0);
		// rl_redisplay(); // pas redisplay pour cat mais redisplay pour heredoc
	}
	else if (sig == SIGQUIT)
		ft_putstr_fd("Quit (core dumped)\n", 2); // Ne pas afficher pour heredoc
}

/*
** 
*/

void	handle_heredoc(int sig)
{
	(void)sig;
	rl_on_new_line();
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}
