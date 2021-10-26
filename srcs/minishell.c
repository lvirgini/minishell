/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:25:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 14:48:38 by lvirgini         ###   ########.fr       */
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

	char	**minishell_env;
	
//testing_structure();
//	exit(0);


	// a voir pour garder la structure t_env ou directement le env du main
	minishell_env = make_minishell_env(env);

	make_terminal(minishell_env);
	free_list(env);

	return (0);
}
