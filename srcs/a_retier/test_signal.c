/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:34:19 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/05 15:18:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"


static int	is_signal(int signal)
{
	if (signal == SIGQUIT)
		return true;
	return false;
}


void		fonction_signal()
{
	printf("OK SIGNAL RECU ! \n");
	exit(EXIT_SUCCESS);
}

void		gestionnaire_de_signal(int signal)
{
	printf("SIGNAL = %d\n", signal);
	if (is_signal(signal))
		return (fonction_signal());
	return(fonction_signal());
}



void		test_signal(void)
{
	signal(SIGQUIT, &gestionnaire_de_signal);
	signal(SIGINT, gestionnaire_de_signal);  /// OK CTRL + C
	signal(SIGSTOP, gestionnaire_de_signal);
	while (1)
	{
		printf("Sleep, waiting ECHAP\n");
		sleep(5);
	}
}