/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:37:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 14:37:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MINISHELL_H
# define TEST_MINISHELL_H

# include "minishell.h"

/*
** ALL TEST FUNCTIONS
*/

void	testing_lexer(void);
void	testing_remove_token(void);
void	testing_ft_get_token(void);
void	testing_env(t_env **env);
void	testing_prompt(t_env **env);
void	testing_convert_double_quote(void);
void	testing_redir(void);
void	testing_parse_redir(void);

/*
** ALL PRINTER FOR EASY VISUALISATION
*/

void	print_token(t_token *token);
void	print_all_token(t_token **token);
void	print_redir(t_redir *redir);
void	print_cmd(t_cmd *cmd);
void	print_list_cmd(t_cmd **cmd);
#endif
