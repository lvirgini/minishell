/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_str_and_expansion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:52:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 18:23:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_expand_len(t_expansion *expansion)
{
	size_t	len;

	len = 0;
	while (expansion)
	{
		if (expansion->value)
			len += ft_strlen(expansion->value[0]);
		expansion = expansion->next;
	}
	return (len);
}

size_t	get_expand_removed_len(t_expansion *expansion)
{
	size_t	len;

	len = 0;
	while (expansion)
	{
		len += expansion->size_to_remove;
		expansion = expansion->next;
	}
	return (len);
}

void	strcpy_expansion(char *new, char *old, t_expansion *expansion)
{
	size_t	old_len;

	old_len = 0;
	while (expansion)
	{
		ft_strncpy(new, old + old_len,
			expansion->start_of_the_expand - old_len);
		new += expansion->start_of_the_expand - old_len;
		old_len = expansion->size_to_remove + expansion->start_of_the_expand;
		if (expansion->value)
		{
			ft_strcpy(new, expansion->value[0]);
			new += ft_strlen(expansion->value[0]);
		}
		expansion = expansion->next;
	}
	ft_strcpy(new, old + old_len);
}

char	*fusion_str_expansion(char *old_s, t_expansion *expansion)
{
	size_t	total_len;
	char	*fusion;

	total_len = get_expand_len(expansion) + ft_strlen(old_s)
		- get_expand_removed_len(expansion);
	fusion = (char *)malloc(sizeof(char) * total_len + 1);
	if (!fusion)
	{
		perror("malloc in fusion_str_expansion()");
		return (NULL);
	}
	strcpy_expansion(fusion, old_s, expansion);
	fusion[total_len] = '\0';
	printf("%s\n", fusion);
	return (fusion);
}
