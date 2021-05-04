/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:43:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/25 13:54:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"
# include <math.h>

typedef struct s_vec2	t_vec2;
typedef struct s_vec3	t_vec3;

struct		s_vec2
{
	double		x;
	double		y;
};

struct		s_vec3
{
	double		x;
	double		y;
	double		z;
};

/*
** Vector 2
*/

t_vec2		create_vec2(double x, double y);
t_vec2		*malloc_vec2(double x, double y);
t_vec2		copy_vec2(t_vec2 a);
t_vec2		add_vec2(t_vec2 a, t_vec2 b);
t_vec2		sub_vec2(t_vec2 a, t_vec2 b);
t_vec2		mul_vec2(t_vec2 a, double t);
double		dot_vec2(t_vec2 a, t_vec2 b);
double		norme2_vec2(t_vec2 a);
double		norme_vec2(t_vec2 a);
t_vec2		normalize_vec2(t_vec2 a);

/*
** Vector 3
*/

t_vec3		create_vec3(double x, double y, double z);
t_vec3		*malloc_vec3(double x, double y, double z);
t_vec3		copy_vec3(t_vec3 a);
t_vec3		add_vec3(t_vec3 a, t_vec3 b);
t_vec3		sub_vec3(t_vec3 a, t_vec3 b);
t_vec3		mul_vec3(t_vec3 a, double t);
t_vec3		mul_vec3_vec3(t_vec3 a, t_vec3 b);
double		dot_vec3(t_vec3 a, t_vec3 b);
double		norme2_vec3(t_vec3 a);
double		norme_vec3(t_vec3 a);
t_vec3		normalize_vec3(t_vec3 a);
t_vec3		cross_vec3(t_vec3 a, t_vec3 b);

#endif
