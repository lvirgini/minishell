/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:37:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/11 15:13:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MINISHELL_H
# define TEST_MINISHELL_H

# include "minishell.h"

/*
** ALL TEST FUNCTIONS
*/

void		testing_lexer(void);
void		testing_ft_get_token(void);
void		testing_env(t_env **env);
void		testing_prompt(t_env **env);
void		testing_convert_double_quote(void);

/*
** ALL PRINTER FOR EASY VISUALISATION
*/

void	print_token(t_token *token);
void	print_all_token(t_token **token);






/* OLD
void	test_wait_fork(void);
void	test_waitpid(void);
void	test_get_cwd(void);
void	gestionnaire_de_signal(int signal);
void	test_signal(void);
void	test_execve(char **env);
char	*test_getenv(void);
void	test_chdir(char**env);
void	test_stat(void);
void	test_opendir(void);
void	test_isatty(void);
void	test_all_termcaps(void);
int		test_prompt(void);
*/
/*
**  test function from minishell
*/


#endif
