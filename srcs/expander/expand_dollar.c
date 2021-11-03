/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 15:36:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand dolar
*/


char	*literal_value_of_dollar(char *str, char **env)
{
	return (get_env_value(env, str + 1));
}

char	**expand_dollar(char *str, char **env)
{
	char 		**split_expansion;
//	char		*value;

	//value = literal_value_of_dollar(str, env);
	split_expansion = ft_split_set(str, STR_ESCAPE);
	return(split_expansion);
	
/*	if (!value)
		expansion->value = NULL; // a verifier pour affichage multi null value
	expansion = 
	if (!expansion)
		return (NULL);
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
*/
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