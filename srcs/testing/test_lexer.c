/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:43:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/15 13:08:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//COPY OF STATIC FUNCTION CAREFULL
static void		set_functions_get_token(t_func ft_token[NB_TOKEN])
{
	ft_token[FT_SIMPLE_QUOTE] = &get_token_simple_quote;
	ft_token[FT_DOUBLE_QUOTE] = &get_token_double_quote;
	ft_token[FT_PIPE] = &get_token_pipe;
	ft_token[FT_TILD_LEFT] = &get_token_tild_left;
	ft_token[FT_TILD_RIGHT] = &get_token_tild_right;
	ft_token[FT_DOLLAR] = &get_token_special_param;
	ft_token[FT_WORD] = &get_token_word;
}

/*
** TEST IS METACHARACTERE
*/

void	testing_is_metacharacter(void)
{
	char	meta[NB_METACHARACTER + 1] = { META_SIMPE_QUOTE, META_DOUBLE_QUOTE,
	META_PIPE, META_TILD_LEFT, META_TILD_RIGHT, META_DOLLAR, ' '};
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
	t_func ft_get_token[NB_METACHARACTER + 1];

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


void	testing_lexer(void)
{
	t_token **token;

/*	char 	*test1 = "cmd1 -arg1 -arg2 | cmd2 arg2";
	token = lexer_minishell(test1);
	print_all_token(token);
	free_all_token(token);*/

	/*char	*test2 = "<infile cmd1 arg1 | cmd2 >outfile";
	token = lexer_minishell(test2);
	print_all_token(token);
	free_all_token(token);*/


	char	*test3 = "\"test.txt\" cmd1 arg1 || cmd2 >\'outfile.txt\' >>`outfile2' ";
	token = lexer_minishell(test3);
	print_all_token(token);
	free_all_token(token);

}

/*
void	testing_parser(void)*/


void	testing_convert_double_quote(void)
{
	char *test1 = "\\\\";  // == "\\" in real minishell
	char *result;

	result = convert_double_quote(test1);
	printf("result = |%s|\n", result);
}