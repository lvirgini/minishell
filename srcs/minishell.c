/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:25:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/11 15:25:02 by lvirgini         ###   ########.fr       */
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

//	testing_convert_double_quote();
//	exit(0);

	t_env	**minishell_env;

//	testing_ft_get_token();
//	testing_lexer();
//	exit(0);



	minishell_env = recover_complete_env(env, argv[0]);
//	testing_env(minishell_env);
//	testing_prompt(minishell_env);

	make_terminal(minishell_env);
	free_all_t_env(minishell_env);
	
	return (0);
}
