/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:51:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 15:27:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_expansion *expand_double_quote(char *s, char **env)
{
	(void)env;
	printf("expand double quotes : %s\n", s);
	return (NULL);
}
