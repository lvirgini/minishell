/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:44:50 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/27 18:58:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 
*/

void	handle_prompt(int sig) // set exit status 130
{
	(void)sig;
	set_exit_status(130, 0);
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
	if (sig == SIGINT) // set exit status 130
	{
		set_exit_status(130, 0);
		printf("\n");
	}
	else if (sig == SIGQUIT)
	{
		set_exit_status(131, 0);
		ft_putstr_fd("Quit\n", 2); // Ne pas afficher pour heredoc
	}
}

/*
** 
*/

void	handle_heredoc(int sig)
{
	(void)sig;
	set_exit_status(130, 0);
	close(0);
	printf("\n");
}
