/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:34:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 19:28:37 by lvirgini         ###   ########.fr       */
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
	test_redir_2(); // OK
}

void	testing_get_next_cmd(void) // OK
{
	t_cmd *cmd;
	t_token **token;

	token = lexer_minishell(" cmd1 -argv1 \" argv2 \" <infile1 <infile2 >outfile3 >$test");
	cmd = get_next_cmd(NULL, token);
	print_cmd(cmd);

	free_list_token(token);
	free_cmd(cmd);
}

void	testing_parser(void)
{
	t_cmd **cmd;
	t_token **token;

//	token = lexer_minishell(" cmd1 <infile -av1 av2 -av3 <infile2 >outfile1 >> \"outfile 2\" | >$OUTFILE2.1 <<infile2.2 cmd2 >outfile2.3 >> outfile2.4");
	token = lexer_minishell("|");
	cmd = parser_minishell(NULL, token);
	print_list_cmd(cmd);

	free_list_token(token);
	free_list_cmd(cmd);
}