/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/12 12:33:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand dollar
*/

char	**expand_dollar(char *str, char **env)
{
	char 		**split_expansion;
	char		*value;

	if (str[1] == '\0')
		split_expansion = ft_split_set(str, STR_ESCAPE);
	else
	{
		value = get_env_value(env, str + 1);
		if (!value)
			split_expansion = ft_split_set("", STR_ESCAPE); // a verifier pour affichage multi null value
		else
			split_expansion = ft_split_set(value, STR_ESCAPE);
	}
	return (split_expansion);
}
