/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:34:19 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/05 17:55:00 by lvirgini         ###   ########.fr       */
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
	if (is_signal(signal) == false)
		exit(EXIT_FAILURE);
	fonction_signal(signal);
	
}

void		sleeping(void)
{
	while (1)
	{
		printf("Sleep, waiting ECHAP\n");
		sleep(5);
	}

}

void		test_signal(void)
{
//	signal(SIGQUIT, &gestionnaire_de_signal);
	signal(SIGINT, gestionnaire_de_signal);  /// OK CTRL + C
	signal(SIGSEGV, gestionnaire_de_signal);
	/* exemple avec SIGSEGV 
	int *tab = NULL; 

	tab[10] = 5;
	printf("%d\n", tab[10]);*/
	
	//char s[256];

	/*	Ctrl D = EOF sans SIGNAL
	while(read(0, s, 256)) 
	{
		printf("%s\n", s);
	}	*/
	

	//sleeping();
}