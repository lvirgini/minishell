/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/26 11:44:11 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** in minishell we don't expand $[0-9], we just pass throw.
*/

static void	dollar_is_digits(t_expansion *expansion)
{
	expansion->size_to_remove = 2;
	expansion->value = NULL;
}

/*
**	Complete expansion with exit status
*/

static void	dollar_is_exit_status(t_expansion *expansion)
{
	expansion->value = malloc_list(1);
	if (!expansion->value)
		free(expansion);
	else
	{
		expansion->size_to_remove = 2;
		expansion->value[0] = ft_itoa(get_exit_status());
	}	
}

/*
** Complete expansion and get value in env.
*/

static void	dollar_is_env_value_split(t_expansion *expansion, char *s,
		char **env)
{
	char		*value;
	char		end_of_key;

	end_of_key = isolate_key(s + 1, expansion);
	value = get_env_value(env, s + 1);
	if (value)
	{
		expansion->value = ft_split_set(value, STR_ESCAPE);
		if (!expansion->value)
		{
			free_list_expansion(expansion);
			return ;
		}
	}	
	s[expansion->size_to_remove] = end_of_key;
}

static void	dollar_is_env_value_literal(t_expansion *expansion, char *s,
		char **env)
{
	char		*value;
	char		end_of_key;

	end_of_key = isolate_key(s + 1, expansion);
	value = get_env_value(env, s + 1);
	if (value)
	{
		expansion->value = ft_split_set(value, "");
		if (!expansion->value)
		{
			free_list_expansion(expansion);
			return ;
		}
	}	
	s[expansion->size_to_remove] = end_of_key;
}

/*
**	return expansion of dollar : it can be :
**
**	$		is "$"
**	$? 		exit status
**	$[0-9]	
**	$[WORD]	env value whith WORD as key
*/

t_expansion	*expand_dollar(char *s, char **env, int is_in_double_quotes)
{
	t_expansion	*expansion;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	if (s[1] == '\0')
		dollar_is_dollar(expansion);
	else
	{
		if (is_dollar_env_value_syntax(s[1]))
		{
			if (is_in_double_quotes)
				dollar_is_env_value_literal(expansion, s, env);
			else
				dollar_is_env_value_split(expansion, s, env);
		}
		else if (ft_isdigit(s[1]))
			dollar_is_digits(expansion);
		else if (s[1] == '?')
			dollar_is_exit_status(expansion);
		else
			dollar_is_dollar(expansion);
	}
	return (expansion);
}
