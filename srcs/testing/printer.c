/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:50:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 19:08:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	if (token)
	{
		printf("token->type = %d\n", token->type);
		if (token->word)
			printf("token->word = %s\n", token->word);
		printf("token->len = %ld\n\n", token->len);
	}
}

void	print_all_token(t_token **token)
{
	t_token	*current;

	current = *token;
	while (current)
	{
		print_token(current);
		current = current->next;
	}
}

void	print_redir(t_redir *redir)
{
	char 	*type_print;
	int		i = 1; 

	while (redir)
	{
		if (redir->type == OUTPUT_REDIRECTION)
			type_print = ">";
		if (redir->type == APPEND)
			type_print = ">>";
		if (redir->type == INPUT_REDIRECTION)
			type_print = "<";
		if (redir->type == HERE_DOC)
			type_print = "<<";
		printf("\tredir %d: type = %s\tfilename = %s\n", i, type_print, redir->filename);
		i++;
		redir = redir->next;
	}
}

void	print_two_tab(char **argv)
{
	int i = 0;

	if (argv)
	{
		while (argv[i])
		{
			printf("\targv[%d] = %s\n",i, argv[i]);
			i++;
		}	
	}
}

void	print_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		printf("cmd->path = %s\n", cmd->path);
		print_two_tab(cmd->argv);
		printf("cmd->type = %d\n", cmd->type);
		printf("input :\n");
		print_redir(cmd->input);
		printf("output :\n");
		print_redir(cmd->output);
	}
	printf("\n");
}

void	print_list_cmd(t_cmd **cmd)
{
	t_cmd *current;
	int		count;

	if (!cmd)
		return ;
	count = 1;
	current = *cmd;
	while (current)
	{
		printf("------------------------------------------------------------\n");
		printf("command %d\n", count);
		print_cmd(current);
		current = current->next;
		count++;
	}
	printf("------------------------------------------------------------\n");


}