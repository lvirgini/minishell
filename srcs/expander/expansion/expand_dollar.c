/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 20:12:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** complete expansion : it is solo "$".
*/

static void	dollar_is_dollar(t_expansion *expansion)
{
	expansion->size_to_remove = 1;
	expansion->value = ft_split_set("$", STR_ESCAPE);
}

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
	(void)expansion;
	// TO DO
}

/*
** Complete expansion and get value in env.
*/

static void	dollar_is_env_value(t_expansion *expansion, char *s, char **env)
{
	char		*value;
	char		end_of_key;

	end_of_key = isolate_key(s + 1, expansion);
	printf("expansion dollar = %s\n", s);
	value = get_env_value(env, s + 1);
	if (value)
		expansion->value = ft_split_set(value, STR_ESCAPE);
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

t_expansion	*expand_dollar(char *s, char **env)
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
			dollar_is_env_value(expansion, s, env);
		else if (ft_isdigit(s[1]))
			dollar_is_digits(expansion);
		else if (s[1] == '?')
			dollar_is_exit_status(expansion);
		else
			dollar_is_dollar(expansion);
	}
	return (expansion);
}
