/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:57:54 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/15 13:10:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
char	*isolate_variable_like_key(char *s)
{

}

static size_t	macro_len(char *s)
{
	size_t	macro_len;
	
	macro_len = 1;
	while(ft_isalnum(s[macro_len]))
		macro_len++;
	return (macro_len);
}

static	char *join_new_quotting_with_variable(char *s, size_t s_len, char *variable)
{
	size_t	i;
	size_t	j;
	size_t	variable_len;
	char	*new_s;


	variable_len = ft_strlen(variable);
	new_s = (char *)malloc(sizeof(char) * (s_len - 1 + variable_len));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < s_len - 1)
	{
		new_s[i] = s[i];
		i++;
	}
	j = 0;
	while (j < variable_len)
		new_s[i++] = variable[j++];
	return (new_s);
}


static char	*replace_this_variable(char *s, size_t i, t_env **env)
{	
	char	*variable;
	char	*key;
	size_t	key_len;
	char	*new_s;

	key_len = macro_len(s[i]);
	key = ft_strdup_max(s[i + 1], key_len - 1);
	if (!key)
	{
		perror("malloc in replace this variable");
		free(s);
		return (NULL);
	}
	variable = get_value_t_env(env, key);
	new_s = join_new_quotting_with_variable(s, variable, i);
	ft_strjoin(new_s, s + i + key_len);
	free(s);
	free(variable);
	free(key);
	free(new_s);
	return (new_s);
}
char	*replace_double_quote_variables(char *s, t_env **env)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && (i == 0 || s[i - 1] != '\\'))
		{
			if (s[i + 1] && ft_isalnum(s[i + 1]))
				s = replace_this_variable(s, i, env);
		}
		else
			i++;	
	}
}
char*/