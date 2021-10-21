/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:43:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 15:47:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//COPY OF STATIC FUNCTION CAREFULL
static void		set_functions_get_token(t_func_get_token ft_token[NB_TOKEN])
{
	ft_token[FT_SIMPLE_QUOTE] = &get_token_simple_quote;
	ft_token[FT_DOUBLE_QUOTE] = &get_token_double_quote;
	ft_token[FT_PIPE] = &get_token_pipe;
	ft_token[FT_TILD_LEFT] = &get_token_tild_left;
	ft_token[FT_TILD_RIGHT] = &get_token_tild_right;
	ft_token[FT_WORD] = &get_token_word;
}

/*
** TEST IS METACHARACTERE
*/

void	testing_is_metacharacter(void)
{
	char	meta[NB_METACHARACTER + 1] = { CHAR_SIMPE_QUOTE, CHAR_DOUBLE_QUOTE,
	CHAR_PIPE, CHAR_TILD_LEFT, CHAR_TILD_RIGHT, CHAR_DOLLAR, ' '};
	int		i;

	i = -1;
	while (++i < NB_METACHARACTER + 1)
		printf("is metacharacter : %c = %d\n", meta[i], is_metacharacter(meta[i]));
}

/*
** TEST DE TOUTES LES FONCTIONS GET_TOKEN_TYPE
*/

void	testing_ft_get_token(void)
{
	t_token	*token;
	t_func_get_token ft_get_token[NB_METACHARACTER + 1];

	set_functions_get_token(ft_get_token);
	
	char	*word = "word    another ";
	char	*pipe = "|";
	char	*exit_status = "$?";
	char	*variable = "$VARIABLEchouette707 26";
	char	*input = "<zz";
	char	*output = ">erert";
	char	*append = ">>sdfsdf";
	char	*here_doc = "<<ssdfsf";

	char	*simple_quote = "\'bla bla bla bla \\\' \\a$?"; //JE NE SAIS PAS COMMENT LE TESTER LA
	token = add_next_token(simple_quote, NULL, ft_get_token);
	print_token(token);
	for (int i = 0; simple_quote[i]; i++)
		printf("%c ", simple_quote[i]);
	printf("\n");

	return ;

	char	*double_quote = "\"word\" trtrtrt";
	token = add_next_token(double_quote, NULL, ft_get_token);
	print_token(token);
	return ;
	token = add_next_token(word, NULL, ft_get_token);
	print_token(token);
	token = add_next_token(pipe, NULL, ft_get_token);
	print_token(token);
	token = add_next_token(exit_status, NULL, ft_get_token);
	print_token(token);
	token = add_next_token(variable, NULL, ft_get_token);
	print_token(token);
	token = add_next_token(input, NULL, ft_get_token);
	print_token(token);
	token = add_next_token(output, NULL, ft_get_token);
	print_token(token);
	token = add_next_token(here_doc, NULL, ft_get_token);
	print_token(token);
	token = add_next_token(append, NULL, ft_get_token);
	print_token(token);
}

void	testing_remove_token(void)
{
	t_token **token;
	t_token *current;
	char	*test = {"	 cmd1  -argv1 \"argv 2\" < inputfile1 <inputfile2 | cmd2 > outputfile2 "};

	token = lexer_minishell(test);

	//	TEST REMOVE FIRST ELEMENT	

/*	*token = remove_multi_token(token, *token, 1);
	print_all_token(token);*/
	

 /*	//	TEST REMOVE ECOND AND ALL REST ELEMENT
	current = (*token)->next;
	remove_multi_token(token, current, 16);
	print_all_token(token);*/
	
/*	// TEST REMOVE ONLY SECOND
	current = (*token)->next;
	remove_multi_token(token, current, 1);
	print_all_token(token);*/


	// TEST REMOVE ALL ELEMENT
/*	*token = remove_multi_token(token, *token, 16);
	print_all_token(token);*/
	

	//TEST REMOVE LAST ELEMENT
	for (current = *token; current->next; current = current->next)
	;
	current = remove_multi_token(token, current, 16);
	print_all_token(token);
	

	free_list_token(token);
}

void	testing_parse_redir(void)
{
	t_cmd *cmd;
	t_token **token;
	char *line = "<< infile1	cmd1 -argv1 <\"infile2 \" \"argv2\" >outfile1 >>outfile1.2 	| <infile2 >outfile2";

	cmd = malloc_cmd(NULL);
	if (!cmd)
		return ;
	token = lexer_minishell(line);
	if (!token)
		return ;
	parse_all_redirection(cmd, token);
	print_cmd(cmd);
	free_cmd(cmd);
	print_all_token(token);
	free_list_token(token);
//	free_list_token(token);
}

void	testing_lexer(void)
{
	t_token **token;

	static char	*test[4] = {
		"     cmd arg1 -arg2 -arg3",
		"cmd | cmd",
		"< \"fileinput.txt\" cmd1 | cmd2 > 'output2'",
		"            	",
	};

	for (int i = 0; i < 4; i++)
	{
		token = lexer_minishell(test[i]);
		if (token)
			print_all_token(token);
		else
			printf("for |%s| token is NULL\n", test[i]);
		free_list_token(token);
	}
}

void	testing_syntax_error(void)
{
	t_token **token;

	static char	*test[] = {
		"||",
		"|", // NO CMD
		">|", //
		"< \"fileinput.txt\" cmd1 | cmd2 > output2'",
		"            	",
	};

	for (int i = 0; i < 4; i++)
	{
		printf("for %s\n", test[i]);
		token = lexer_minishell(test[i]);
		if (token)
			print_all_token(token);
		else
			printf("token is NULL\n");
		free_list_token(token);
	}
}

/*
void	testing_parser(void)*/


void	testing_convert_double_quote(void)
{
	//char *test1 = "\\\\";  // == "\\" in real minishell
	//char *result;

//	result = convert_double_quote(test1);
//	printf("result = |%s|\n", result);
}