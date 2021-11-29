/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 14:30:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

/*
** in minishell we don't expand $[0-9], we just pass throw.
*/

static t_expansion	*dollar_is_digits(void)
{
	t_expansion	*expansion;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	expansion->size_to_remove = 2;
	expansion->value = NULL;
	return (expansion);
}

static t_expansion	*dollar_is_exit_status(void)
{
	t_expansion	*expansion;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	expansion->value = malloc_list(1);
	if (!expansion->value)
	{
		expansion->size_to_remove = 2;
		expansion->value[0] = ft_itoa((int)g_exit.status);
		if (expansion->value[0] == NULL)
		{
			free_list_expansion(expansion);
			return (NULL);
		}
	}
	return (expansion);
}

/*
** Complete expansion and get value in env.
*/

static t_expansion	*dollar_is_env_value_split(char *s, char **env)
{
	char		*value;
	char		end_of_key;
	t_expansion	*expansion;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	end_of_key = isolate_key(s + 1, expansion);
	value = get_env_value(env, s + 1);
	if (value)
	{
		expansion->value = ft_split_set(value, STR_ESCAPE);
		if (!expansion->value)
		{
			free_list_expansion(expansion);
			return (NULL);
		}
	}	
	s[expansion->size_to_remove] = end_of_key;
	return (expansion);
}

static t_expansion	*dollar_is_env_value_literal(char *s, char **env)
{
	char		*value;
	char		end_of_key;
	t_expansion	*expansion;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	end_of_key = isolate_key(s + 1, expansion);
	value = get_env_value(env, s + 1);
	if (value)
	{
		expansion->value = ft_split_set(value, "");
		if (!expansion->value)
		{
			free_list_expansion(expansion);
			return (NULL);
		}
	}	
	s[expansion->size_to_remove] = end_of_key;
	return (expansion);
}

/*
**	return expansion of dollar : it can be :
**
**	$		is "$"
**	$? 		exit status
**	$[0-9]	is nothing in minishell
**	$[WORD]	env value whith WORD as key
*/

t_expansion	*expand_dollar(char *s, char **env, int is_in_double_quotes)
{
	if (s[1] == '\0')
		return (dollar_is_dollar());
	if (s[1] == '?')
		return (dollar_is_exit_status());
	if (ft_isdigit(s[1]))
		return (dollar_is_digits());
	if (is_dollar_env_value_syntax(s[1]))
	{
		if (is_in_double_quotes)
			return (dollar_is_env_value_literal(s, env));
		else
			return (dollar_is_env_value_split(s, env));
	}
	return (dollar_is_dollar());
}
