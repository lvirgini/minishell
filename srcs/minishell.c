/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:25:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 21:30:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	
**	ATTENTION pas de doublon dans les variables d'environnements
*/

void		testing_env(t_env **env)
{
//	print_all_env(env);
//	print_this_env(get_this_env(env, "USER"));
	edit_or_add_t_env(env, "USER", "prout");
	//print_this_env(get_this_env(env, "USER"));
	remove_t_env(env, "USER");
//	print_this_env(get_this_env(env, "USER"));
	remove_t_env(env, "USER");
	//add_front_env(env, add_new_env("USER", "addfront"));
	//add_front_env(env, add_new_env("USER", "addfront2"));
	print_all_env(env);
//	print_all_env(env);
}

int		main(int argc, char *argv[], char *env[])
{
	(void)argc;
//	(void)argv;

	t_env	**my_env;

	my_env = recover_complete_env(env, argv[0]);
	testing_env(my_env);
	free_all_t_env(my_env);
	//make_terminal();
	
	return (0);
}
