/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:13:46 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 15:42:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_split_set(const char *s, const char *set)
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
