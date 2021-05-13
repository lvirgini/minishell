/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:55:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/06 15:46:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

/*
** Use with NULL or malloc before but if is malloc size < getpwd remalloc. 
** Using tab[] is clearly not to do !
**
** ret : NULL : getpwd malloc				and free
** ret_malloc : malloc before getpwd		careful the size of malloc sinon leaks
** ret_tab 	  : tab longueur definit		
*/


void	test_get_cwd(void)
{
	printf("\nTEST GETCWD : \n");
	char *ret;
	char *ret_malloc;
	char ret_tab[50];
	char ret_tab2[10];

	// ret : NULL : getpwd malloc
	ret = NULL;
	ret = getcwd(NULL, 0);

	// ret_malloc : malloc before getpwd /\ au leaks !! si size < getcwd
	ret_malloc = (char *)malloc(sizeof(char) * 50);
	if (ret_malloc == NULL)
		exit(EXIT_FAILURE);
	ret_malloc = getcwd(ret_malloc, 50);
	//ret_malloc = getcwd(ret_malloc, 10); /// return NULL and LEAK

	// ret_tab = tableau longueur definit
	getcwd(ret_tab, 50);
	getcwd(ret_tab2, 10);
	

	printf("getcwd char * NULL 	= %s\n", ret);
	printf("getcwd char * malloc	= %s\n", ret_malloc);
	printf("getcwd char[50]		= %s\n", ret_tab);
	printf("getcwd char[10]		= %s\n", ret_tab2);

	free(ret_malloc);
	free(ret);
}