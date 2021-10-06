/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:25:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/06 13:50:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	
**	ATTENTION pas de doublon dans les variables d'environnements
**	ATTENTION lors de l'affichage des valeurs NULL : peut etre plus judicieux de mettre "" que NULL ?
**		a test echo $TRUC if TRUC= ""  ou TRUC = NULL;
*/

void		testing_env(t_env **env)
{

	// test edit / remove / 
/*	print_this_env(get_this_env(env, "USER"));
	edit_or_add_t_env(env, "USER", "prout");
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
