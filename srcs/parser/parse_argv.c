/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:36:34 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 19:34:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_argc_for_next_cmd(t_token **list_token)
{
	int		argc;
	t_token	*token;

	argc = 0;
	token = *list_token;
	while (token && is_token_control_operator(token->type) == false)
	{
		argc++;
		token = token->next;
	}
	return (argc);
}

static int	add_cmd_arguments_from_token(char **argv, t_token *token, int argc)
{
	int	i;

	i = 0;
	while (token && i < argc)
	{
		argv[i] = ft_strdup(token->word);
		if (!argv[i])
			return (FAILURE);
		i++;
		token = token->next;
	}
	argv[argc] = NULL;
	return (SUCCESS);
}

int	parse_cmd_argv(t_cmd *cmd, t_token **list_token)
{
	t_token	*token;
	int		argc;

	token = *list_token;
	if (!token)
		return (SUCCESS); // IL FAUDRA CHECK SI CMD->ARGV EXISTE POUR LANCER LA CMD
	argc = get_argc_for_next_cmd(list_token);
	if (argc == 0)
		return (SUCCESS);
	cmd->argv = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!cmd->argv)
		return (FAILURE);
	if (add_cmd_arguments_from_token(cmd->argv, *list_token, argc) == FAILURE)
		return (FAILURE);
	remove_multi_token(list_token, *list_token, argc);
	return (SUCCESS);
}