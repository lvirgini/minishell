/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:26:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 15:22:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

static size_t	count_nb_list(const char *s, char c)
{
	size_t	nb_list;

	nb_list = 0;
	while (*s)
	{
		if (*s != c)
		{
			nb_list++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (nb_list);
}

static char	**make_split(const char *s, char c, char **list, size_t nb_list)
{
	int	len_list;

	while (*s)
	{
		if (*s != c)
		{
			len_list = ft_strchr_len(s, c);
			if (len_list == -1)
				len_list = ft_strlen(s);
			*list = ft_strdup_max(s, len_list);
			if (!*list)
			{
				free_list(list);
				return (NULL);
			}
			list++;
			s += len_list;
		}
		else
			s++;
	}
	*list = NULL;
	return (list - nb_list);
}

char	**ft_split(const char *s, const char c)
{
	size_t	nb_list;
	char	**list;

	if (!s)
		return (NULL);
	nb_list = count_nb_list(s, c);
	list = (char **)malloc(sizeof(char *) * (nb_list + 1));
	if (!list)
		return (NULL);
	make_split(s, c, list, nb_list);
	return (list);
}
