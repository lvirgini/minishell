/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:41:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/13 12:07:06 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"
#include <limits.h>


char		*test_getenv(void)
{
	char *env;
	char *name_env = "PATH";

	env = NULL;
	env = getenv(name_env);
	if (env == NULL)
		printf("test_getenve : char *env = NULL for %s\n", name_env);
	else
		printf("getenv = %s\n", env);
	return (env);
}

void		test_execve(char **env)
{	
	char	*argv[] = { "path", "-l", "-a", NULL};
	int		status;	
	pid_t 	pid;

	signal(SIGTRAP, gestionnaire_de_signal); /// NE COMPREND PAS CE QUE FAIT SIGTRAP
	pid = fork();
	if (pid == -1)
	{
		perror("Error creation pid_t");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{	
		printf("IN PID FOR EXECVE\n");
		int ret = execve("/home/mini/42/minishell/a.out",argv, env);
		printf("AFTER EXERVE ret = %d\n", ret);
	}
	if (wait(&status) == -1)
	{
		printf("IN ERROR status = %d\n", status);
    	perror("Erreur lors de l'attente du fils 1");
		exit(EXIT_FAILURE);
  	}
	printf("status = %d\n", status);
}
