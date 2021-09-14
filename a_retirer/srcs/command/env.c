/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:11:58 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/16 14:13:47 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_env(t_env *env)
{
	while (env)
	{
		ft_putstr(env->key);
		ft_putstr("=");
		ft_putstr(env->value);
		ft_putstr("\n");
		env = env->next;
	}
}