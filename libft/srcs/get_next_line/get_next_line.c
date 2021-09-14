/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:28:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/22 16:41:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** STRJOIN pour gnl
*/

static char	*ft_strjoin_gnl(char *s1, char const *s2, size_t s2_len)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*dest;

	if (!s2)
		return (NULL);
	len = s2_len + ft_strlen(s1);
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (i < s2_len)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

/*
** Copie tout ou une partie de buf dans line.
*/

static int	copy_buf_in_line(char **line, char *buf, int end_of_line, int len)
{
	if (end_of_line == -1)
	{
		if (len <= 0)
			len = ft_strlen(buf);
	}
	else
		len = end_of_line;
	if (buf[0] == '\n')
		len = 0;
	*line = ft_strjoin_gnl(*line, buf, len);
	if (len == BUFFER_SIZE)
	{
		len = -1;
		buf[0] = '\0';
	}
	buf = ft_strncpy(buf, buf + len + 1, BUFFER_SIZE);
	return (1);
}

/*
** quand la fonction (read) a entierement lu le fd, ou si pb (-1)
*/

static int	stop_read(char **line, char *buf, int end_of_line, int len)
{
	if (len == -1)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		return (-1);
	}
	else
	{
		if (buf[0] == '\0')
			return (0);
		end_of_line = ft_strchr_len(buf, '\n');
		if (end_of_line >= 0 || ft_strlen(buf) > 0)
		{
			copy_buf_in_line(line, buf, end_of_line, len);
			return (1);
		}
		free(*line);
		*line = NULL;
		return (0);
	}
}

/*
** Recherche l'index de la structure correspondante au fd.
*/

static int	find_t_gnl(t_gnl gnl[NB_FD], int fd)
{
	int		i;

	i = 0;
	while (gnl && gnl[i].fd != 0 && gnl[i].fd != fd)
		i++;
	if (gnl[i].fd == 0)
		gnl[i].fd = fd;
	return (i);
}

/*
**  GNL :
**	- tant que (\n) n'est pas ete trouve dans le buffer, on lit le fd.
**	tout en copiant le buffer dans *line.
**	- on arrete de (read) des (\n).
**	- retourne 1 pour chaque ligne copiee.
**	- retourne 0 si EOF.
*/

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl[NB_FD];
	int				i;
	int				end_of_line;
	int				len;

	*line = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, gnl[0].buf, 0) == -1))
		return (-1);
	i = find_t_gnl(gnl, fd);
	len = 0;
	*line = ft_strjoin_gnl(NULL, gnl[i].buf, 0);
	end_of_line = ft_strchr_len(gnl[i].buf, '\n');
	while (end_of_line < 0)
	{
		if (copy_buf_in_line(line, gnl[i].buf, end_of_line, len) != 1)
			return (stop_read(line, gnl[i].buf, end_of_line, len));
		len = read(fd, gnl[i].buf, BUFFER_SIZE);
		if (len < BUFFER_SIZE)
			return (stop_read(line, gnl[i].buf, end_of_line, len));
		end_of_line = ft_strchr_len(gnl[i].buf, '\n');
	}
	return (stop_read(line, gnl[i].buf, end_of_line, len));
}
