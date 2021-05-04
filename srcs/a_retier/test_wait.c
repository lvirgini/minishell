/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:01:44 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/04 12:37:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** pris de https://www.cyril-rabat.fr/articles/index.php?article=19
*/

static void		processus_fils(void)
{
	for (int i = 0; i < 5; i++)
	{
		printf("FILS = %d \n", i);
		sleep(1);
	}
	printf("FILS = FINI\n");
	exit(EXIT_SUCCESS);
}

static void		processus_pere(void)
{
		for (int i = 0; i < 5; i++)
	{
		printf("PERE = %d \n", i);
		sleep(1);
	}
}
void			test_wait_fork(void)
{
	pid_t	pid;
	int		status;

	 /* Creation du processus fils */
	pid = fork();
	if (pid == -1)
	{
		perror("Error creation");
		exit(EXIT_FAILURE);
	}

	 /* processus fils */
	if (pid == 0)
		processus_fils();

	/* processus parent */
	processus_pere();
	printf("PERE : j'attends la fin du fils\n");
	if (wait(&status) == -1)
	{
    	perror("Erreur lors de l'attente du fils ");
		exit(EXIT_FAILURE);
  	}
	if(WIFEXITED(status))
   		printf("Le fils a termine ; valeur retournee = %d\n", WEXITSTATUS(status));
  else
    	printf("Le fils a termine anormalement.\n");
}