/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:11:10 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 12:11:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** pass the spaces in the line and return the ptr.
*/

char	*pass_str_spaces(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	return (line);
}
