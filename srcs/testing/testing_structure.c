/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:18:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 14:21:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	testing_structure(void)
{
	t_expansion *exp;
	t_expansion *exp2;

	exp = malloc_expansion();
//	exp->value = "pouet";
	exp->next = NULL;
	exp2 = malloc_expansion();
//	exp2->value = "2eme";
	exp2->next = NULL;
	struct_add_back((t_struct *)exp, (t_struct *)exp2);

}