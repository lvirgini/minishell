/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:55:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/04 18:19:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

/*
** Use with NULL or malloc before but if is malloc size < getpwd remalloc. 
** Using tab[] is clearly not to do !
**
** ret : NULL : getpwd malloc
** ret_malloc : malloc before getpwd
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

	// ret_malloc : malloc before getpwd
	ret_malloc = (char *)malloc(sizeof(char) * 10);
	if (ret_malloc == NULL)
		exit(EXIT_FAILURE);
	ret_malloc = getcwd(ret_malloc, 50);

	// ret_tab = tableau longueur definit
	getcwd(ret_tab, 50);
	getcwd(ret_tab2, 10);
	

	printf("NULL = %s\nmalloc = %s\ntab[50] = %s\ntab[10] = %s\n",
	ret, ret_malloc, ret_tab, ret_tab2);

	free(ret_malloc);
	free(ret);
}