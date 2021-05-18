/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:37:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 11:15:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MINISHELL_H
# define TEST_MINISHELL_H

# include "minishell.h"

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

/*
**  test function from minishell
*/

int		test_prompt(void);

#endif
