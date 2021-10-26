/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 14:34:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand dolar
*/

t_expansion		*expand_dollar(char *str, char **env)
{
	t_expansion *expansion;
	char		*value;
	size_t		i;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	value = get_env_value(env, str + 1);
	if (!value)
		expansion->value = NULL; // a verifier pour affichage multi null value
	while (str)
	{
		value = NULL;//
		pass_str_spaces(str);
		//value = get_next_value(str);
		if (!value && str)
		{
			free_list_expansion(expansion);
			return (NULL);
		}
	//	add_back_expansion(expansion, value);
	}
	return (expansion);
}





/*
char	*expand_variable(char **env, char *key)
{
	char	*value;
	char	*result;

	value = get_env_value(env, key + 1);
	if (!value) //// A TESTER
	{
		result = (char *)malloc(sizeof(char));
		if (result)
			*result = "\0";
	}	
	else
		result = ft_strdup(value);
	free(key);
	if (!result)
	{
		perror("malloc in expand_variable()");
		return (NULL);
	}
	return (result);
}
*/