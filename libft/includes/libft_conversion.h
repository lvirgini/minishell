/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_conversion.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:28:09 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 16:00:37 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONVERSION_H
# define LIBFT_CONVERSION_H

# include "libft.h"

/*
** Fonctions de conversion
*/

int			ft_atoi(const char *s);
int			ft_atoi_base(char *str, char *base);
long long	ft_atoll(const char *str);
double		ft_atof(const char *str);
int			ft_atoi_i(const char *s, int *result);
int			ft_atof_i(const char *str, double *result);
char		*ft_itoa(int n);
char		*ft_lltoa(long long int n);
char		*ft_utoa(unsigned int n);
char		*ft_ulltoa(unsigned long long int n);

#endif
