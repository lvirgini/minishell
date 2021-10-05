/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:11:58 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 17:11:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_this_env(t_env *env)
{
	if (env)
	{
		ft_putstr(env->key);
		ft_putstr("=");
		ft_putstr(env->value);
		ft_putstr("\n");
	}
}

void	print_all_env(t_env **env)
{
	t_env	*current;

	current = *env;
	while (current)
	{
		print_this_env(current);
		current = current->next;
	}
}
