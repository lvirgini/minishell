/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:28:09 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/28 11:33:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINT_H
# define LIBFT_PRINT_H

# include "libft.h"

/*
** Fonctions d'impression
*/

void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char *s);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr_base_fd(int nbr, char *base, int fd);
void		ft_putstr(char *s);
void		ft_putstr_fd(char *s, int fd);

#endif
