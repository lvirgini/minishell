/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 13:15:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand dollar
*/

t_expansion	*expand_dollar(char *s, char **env)
{
	//(void)s;
	(void)env;
	printf("expand dollar : %s\n", s);
	return (NULL);
	/*
	t_expansion	*expansion;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	if (str[1] == '\0')
	{
		expansion->start_of_the_expand
	}
*/
}
/*
char	**expand_dollar(char *str, char **env)
{
	char		**split_expansion;
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
*/