/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:16:55 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/04 12:46:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	use_new_functions(void)
{
	test_wait_fork();
	test_get_cwd();
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("IN TEST \n\n");

	use_new_functions();
	return (0);
}
