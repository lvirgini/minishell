/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:25:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 14:06:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	
** MINISHELL by eassouli and lvirgini
*/

int	main(int argc, char *argv[], char *env[])
{
	char	**minishell_env;

	(void)argc;
	(void)argv;
	if (!isatty(STDIN_FILENO))
	{
		display_error(ERR_STDIN_MINISHELL, NULL);
		return (EXIT_FAILURE);
	}	
	minishell_env = make_minishell_env(env);
	if (!minishell_env)
		return (EXIT_FAILURE);
	export_keyvalue(OLDPWD, &minishell_env);
	make_terminal(&minishell_env);
	free_list(minishell_env);
	return (get_exit_status());
}
