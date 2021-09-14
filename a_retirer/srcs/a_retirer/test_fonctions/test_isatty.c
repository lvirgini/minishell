/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isatty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:25:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/13 14:26:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

void		test_isatty(void)
{
	//char	*path = "srcs/a_retirer/test_chdir.c";

	printf("fd = %d\nisatty = %d\n", 1, isatty(1));
	printf("ttyname = %s\n", ttyname(1));
	printf("ttyslot = %d\n", ttyslot());
}
