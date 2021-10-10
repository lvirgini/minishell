/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:50:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/10 15:50:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	if (token)
	{
		printf("token->type = %d\n", token->type);
		printf("token->word = %s\n", token->word);
		printf("token->len = %ld\n\n", token->len);
	}
}
