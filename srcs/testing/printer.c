/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:50:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 15:05:56 by lvirgini         ###   ########.fr       */
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
	int	i = 1; 
	while (redir)
	{
		printf("\tredir %d: type = %d\tfilename = %s\n", i, redir->type, redir->filename);
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
		printf("cmd->path = %s", cmd->path);
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

	if (!cmd)
		return ;
	current = *cmd;
	while (current)
	{
		print_cmd(current);
		current = current->next;
	}
}