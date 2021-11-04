/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/04 12:20:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand dolar
*/

/*
char	*literal_value_of_dollar(char *str, char **env)
{
	return (get_env_value(env, str + 1));
}*/
static int	count_nb_list(char	*s, char *set)
{
	int	nb_list;
	int	i;

	nb_list = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_strchr(set, s[i]))
		{
			nb_list++;
			while (s[i] && !ft_strchr(set, s[i]))
				i++;
		}
		else
			i++;
	}
	return (nb_list);
}

void	complete_the_list(char *s, char *set, char **list)
{
	int	len;

	if (!*s)
		*list = NULL;
	while (*s)
	{
		if (!ft_strchr(set, *s))
		{
			len = ft_strchr_set_len(s, set);
			if (len < 0)
				len = ft_strlen(s);
			*list = ft_strdup_max(s, len);
			if (!*list)
			{
				free_list(list);
				return ;
			}	
			s += len;
		}
		else
			s++;
	}
}

char	**ft_split_set2(const char *s, const char *set)
{
	size_t	count_list;
	char	**list;

	if (!s || !set)
		return (NULL);
	count_list = count_nb_list((char *)s, (char *)set);
	list = (char **)malloc(sizeof(char *) * (count_list + 1));
	if (!list)
		return (NULL);
	complete_the_list((char *)s, (char *)set, list);
	return (list);
}

char	**expand_dollar(char *str, char **env)
{
	char 		**split_expansion;
	char		*value;

	value = get_env_value(env, str + 1);
	if (!value)
		split_expansion = ft_split_set2("", STR_ESCAPE); // a verifier pour affichage multi null value
	else
		split_expansion = ft_split_set2(value, STR_ESCAPE);
	print_list(split_expansion); //
	return (split_expansion);
/*

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