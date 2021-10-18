/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:25:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/18 21:56:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	
**	ATTENTION pas de doublon dans les variables d'environnements
**	ATTENTION lors de l'affichage des valeurs NULL : peut etre plus judicieux de mettre "" que NULL ?
**		a test echo $TRUC if TRUC= ""  ou TRUC = NULL;
*/

int		main(int argc, char *argv[], char *env[])
{
	(void)argc;

	t_env	**minishell_env;
	
	// a voir pour garder la structure t_env ou directement le env du main
	minishell_env = recover_complete_env(env, argv[0]);

	make_terminal(minishell_env);
	free_all_t_env(minishell_env);

	return (0);
}
