/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:16:55 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/07 16:23:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	use_new_functions(char **env)
{
	//test_wait_fork();
	//test_waitpid();
	//test_get_cwd();
	//test_signal();
//	test_execve(env); // + test_get_env()
	//test_chdir(env);
	//test_stat();
	//test_opendir();
//	test_isatty();
	test_getenv();
	test_all_termcaps();

	
}

int		main(int argc, char **argv, char **env)
{

	(void)argc;
	(void)argv;
	printf("IN TEST \n\n");

	use_new_functions(env);
	/*for (int i = 0; env[i]; i++)
		printf("env[%d] = %s\n", i, env[i]);*/
	return (0);
}
