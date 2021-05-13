/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_execve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:04:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/06 15:05:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("IN main test execve programm \n");
	
	for (int i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	
	return (0);
}