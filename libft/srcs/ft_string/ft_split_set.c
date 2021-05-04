/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 09:11:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/04/01 10:29:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Retourne un tableau de char * obtenu en séparant *s à l'aide
** des caractères du (set), utilisé comme délimiteur.
** le tableau doit être terminé par NULL.
*/

static char		**free_split_exit(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	split_count_nb_tab(const char *s, const char *set)
{
	size_t	nb_tab;

	nb_tab = 0;
	while (*s)
	{
		if (!ft_strchr(set, *s))
		{
			nb_tab++;
			while (*s && !ft_strchr(set, *s++))
				;
		}
		else
			s++;
	}
	return (nb_tab);
}

char			**ft_split_set(const char *s, const char *set)
{
	size_t		nb_tab;
	size_t		len_tab;
	char		**tab;

	if (!s)
		return (NULL);
	nb_tab = split_count_nb_tab(s, set);
	if (!(tab = malloc(sizeof(tab) * (nb_tab + 1))))
		return (NULL);
	while (*s)
	{
		if (!ft_strchr(set, *s))
		{
			len_tab = ft_strlen_set(s, set);
			if (!(*tab = ft_strdup_max(s, len_tab)))
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

/*
** creer un char * avec pour seul element c puis utilise split_set
*/

static void		get_set_split(char set[2], char c)
{
	set[0] = c;
	set[1] = '\0';
}

char			**ft_split_count(const char *s, const char c, size_t *size)
{
	size_t		len_tab;
	char		**tab;
	char		set[2];

	get_set_split(set, c);
	if (!s)
		return (NULL);
	*size = split_count_nb_tab(s, set);
	if (!(tab = malloc(sizeof(tab) * (*size + 1))))
		return (NULL);
	while (*s)
	{
		if (!ft_strchr(set, *s))
		{
			len_tab = ft_strlen_set(s, set);
			if (!(*tab = ft_strdup_max(s, len_tab)))
				return (free_split_exit(tab));
			tab++;
			s += len_tab;
		}
		else
			s++;
	}
	*tab = NULL;
	return (tab - *size);
}
