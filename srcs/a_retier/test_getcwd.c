/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:55:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/03 19:07:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

/*
** Use with NULL or malloc before but if is malloc size < getpwd remalloc. 
** Using tab[] is clearly not to do !
*/

void	test_get_cwd(void)
{
	printf("TEST GETCWD : \n");
	char *ret;
	char *ret_malloc;
	char ret_tab[50];
	char ret_tab2[10];

	/* ret : NULL : getpwd malloc
	** ret_malloc : malloc before getpwd
	** ret_tab = tab[50] */

	ret = NULL;
	ret_malloc = (char *)malloc(sizeof(char) * 10);
	if (ret_malloc == NULL)
		exit(EXIT_FAILURE);

	ret = getcwd(NULL, 0);
	ret_malloc = getcwd(ret_malloc, 50);
	getcwd(ret_tab, 50);

	printf("NULL = %s\nmalloc = %s\ntab[50] = %s\ntab[10]= %s\n", ret, ret_malloc, ret_tab, ret_tab2);

	free(ret_malloc);
	free(ret);
}