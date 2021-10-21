/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:34:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 15:46:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	test_redir_1(void)
{
	t_redir *r;
	t_token	token;

	token.word = "file";
	r = add_redir(&token);
	token.word = "file2";
	add_back_redir(r, add_redir(&token));
	token.word = "file3";
	add_back_redir(r, add_redir(&token));
	print_redir(r);
	free_list_redir(r);
}

void	test_redir_2(void)
{
	t_cmd *cmd;
	t_token **token;

	char *line = "< infile1 < infile2 < \"infile3\" > outfile1 > outfile2 > \"outfile3\"";
	
	token = lexer_minishell(line);
//	print_all_token(token);
	cmd = malloc_cmd(NULL);
	parse_all_redirection(cmd, token);
	print_cmd(cmd);
	free_cmd(cmd);

}

void	testing_redir(void)
{
	test_redir_1(); // OK
	test_redir_2();


/*	t_cmd *cmd;
	t_token	**token = lexer_minishell("> outfile");


	cmd = malloc_cmd(NULL);
	cmd->input = malloc_redir(*token);
	print_cmd(cmd);*/

}