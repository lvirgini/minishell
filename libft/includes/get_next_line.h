/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:22:56 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/22 11:15:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** GET NEXT LINE . c
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef NB_FD
#  define NB_FD 1
# endif

typedef struct s_gnl	t_gnl;

struct			s_gnl
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
};

int				get_next_line(int fd, char **line);

#endif
