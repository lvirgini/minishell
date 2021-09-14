/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:14:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/06 16:52:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"
#include <sys/stat.h>
 
void		test_stat(void)
{
	struct stat vstat;

	int ret = lstat("/home/mini/42/", &vstat);
	if (ret == -1)
	{
		printf("error stat return -1\n");
		return ;
	}
	printf("stat.st_mode = %d\n", vstat.st_mode); 
	printf("S_ISREG = %d\n", S_ISREG(vstat.st_mode));
	printf("S_ISDIR = %d\n", S_ISDIR(vstat.st_mode));
	printf("S_ISCHR = %d\n", S_ISCHR(vstat.st_mode));
	
}