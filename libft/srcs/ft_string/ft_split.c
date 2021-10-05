/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:26:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/21 14:43:17 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split_exit(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	count_nb_tab(const char *s, char c)
{
	size_t	nb_tab;

	nb_tab = 0;
	while (*s)
	{
		if (*s != c)
		{
			nb_tab++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (nb_tab);
}

static char	**make_split(const char *s, char c, char **tab, size_t nb_tab)
{
	int	len_tab;

	while (*s)
	{
		if (*s != c)
		{
			len_tab = ft_strchr_len(s, c);
			if (len_tab == -1)
				len_tab = ft_strlen(s);
			*tab = ft_strdup_max(s, len_tab);
			if (!*tab)
				return (free_split_exit(tab));
			tab++;
			s += len_tab;
		}
		else
			s++;
	}
	*tab = NULL;
	return (tab - nb_tab);
}

char	**ft_split(const char *s, const char c)
{
	size_t	nb_tab;
	char	**tab;

	if (!s)
		return (NULL);
	nb_tab = count_nb_tab(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_tab + 1));
	if (!tab)
		return (NULL);
	return (make_split(s, c, tab, nb_tab));
}
