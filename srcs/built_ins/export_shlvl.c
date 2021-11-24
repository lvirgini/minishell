/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:19:00 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/24 18:04:36 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*new_nb(char *value)
{
	int		nb;
	char	*new_nb_value;

	nb = ft_atoi(value);
	new_nb_value = ft_itoa(nb + 1);
	return (new_nb_value);
}

void	export_shlvl(char ***env)
{
	char		*value;
	char		*new_value;
	static char	*shlvl[3];

	shlvl[2] = NULL;
	value = get_env_value(*env, SHLVL);
	new_value = new_nb(value);
	if (value == NULL || new_value == NULL)
	{
		shlvl[1] = SHLVL0;
		exec_export(shlvl, env);
		return ;
	}
	shlvl[1] = ft_strjoin(SHLVL, new_value);
	if (shlvl[1])
		exec_export(shlvl, env);
	free(new_value);
	if (shlvl[1])
		free(shlvl[1]);
}
