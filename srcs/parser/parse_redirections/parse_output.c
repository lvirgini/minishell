/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:42:46 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/18 16:34:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_output(t_cmd *cmd, t_token *token)
{
	if (!cmd->output)
		cmd->output = parse_redir(token);
	else
		add_back_t_redir(cmd->output, parse_redir(token));
	return (1);////
}
