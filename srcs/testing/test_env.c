/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:51:46 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/10 15:56:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		testing_env(t_env **env)
{

	// test edit / remove / 
	print_this_env(get_this_env(env, "USER"));
	/*edit_or_add_t_env(env, "USER", "prout");
	print_this_env(get_this_env(env, "USER"));
	remove_t_env(env, "USER");
	print_this_env(get_this_env(env, "USER"));*/

	// test print all env
/*	print_all_env(env);*/

	// test print all env / remove
/*	print_all_env(env);
	remove_t_env(env, "USER");*/

	// test add NULL or empty value
/*	print_this_env(get_this_env(env, "USER"));
	edit_or_add_t_env(env, "USER", NULL);
	print_this_env(get_this_env(env, "USER"));
	edit_or_add_t_env(env, "USER", "");
	print_this_env(get_this_env(env, "USER"));*/

	// test remove
/*	remove_t_env(env, "PATH");
	print_all_env(env);
	print_this_env(get_this_env(env, "PATH"));*/

}