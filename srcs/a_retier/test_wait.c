/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:01:44 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/05 14:37:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** pris de https://www.cyril-rabat.fr/articles/index.php?article=19
**
** fork : le fils commence a la prochaine instruction apres fork.

** 
*/

static void		processus_fils(int	nb)
{
	for (int i = 0; i < nb * 2; i++)
	{
		printf("FILS %d= %d \n", nb, i);
		sleep(1);
	}
	printf("FILS %d= FINI\n", nb);
	exit(EXIT_SUCCESS);
}

static void		processus_pere(int nb)
{
		for (int i = 0; i < nb; i++)
	{
		printf("PERE %d = %d \n", nb, i);
		sleep(1);
	}
}


pid_t			get_pid_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error creation pid_t");
		exit(EXIT_FAILURE);
	}
	return (pid);

}
void			test_wait_fork(void)
{
	pid_t	pid;
	int		status;

	 /* Creation du processus fils */
	pid = get_pid_fork();
	if (pid == 0)
		processus_fils(1);

	/* processus parent */
	processus_pere(1);
	printf("PERE : en attente du fils 1 \n");
	if (wait(&status) == -1)
	{
    	perror("Erreur lors de l'attente du fils 1");
		exit(EXIT_FAILURE);
  	}
	if(WIFEXITED(status))
   		printf("Le fils 1 a termine ; valeur retournee = %d\n", WEXITSTATUS(status));
  else
    	printf("Le fils 1 a termine anormalement.\n");
}

/*
** A tester seul pour voir le processus 3 finir apres la fin du programme pere...
**
*/
void		test_waitpid(void)
{
	pid_t	pid2;
	pid_t	pid3;
	int		status2;
	int		status3;

	pid2 = get_pid_fork();
	/*pid3 = get_pid_fork(); si placé ici je ne comprends pas 
	** 2*fils 2 et 1 fois fils 3 donc 2 fois fork pid3 ? */
	if (pid2 == 0)
		processus_fils(2);

	pid3 = get_pid_fork();
	if (pid3 == 0)
		processus_fils(3);
	processus_pere(2);

	/* Retour fils 1 */
	printf("PERE : en attente du fils 2 \n");
	if (waitpid(pid2, &status2, 0) == -1)
	{
		perror("Erreur lors de l'attente du fils 2 ");
		exit(EXIT_FAILURE);
	}
	if(WIFEXITED(status2))
   		printf("Le fils 2 a termine ; valeur retournee = %d\n", WEXITSTATUS(status2));
  	else
    	printf("Le fils 2 a termine anormalement.\n");



	/* retour fils 2 */
	printf("PERE : en attente du fils 3 \n");
	if (waitpid(pid3, &status3, 0) == -1)
	{
		perror("Erreur lors de l'attente du fils 3 ");
		exit(EXIT_FAILURE);
	}
	if(WIFEXITED(status3))
   		printf("Le fils 3 a termine ; valeur retournee = %d\n", WEXITSTATUS(status3));
 	else
    	printf("Le fils 3 a termine anormalement.\n");
}
