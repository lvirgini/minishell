/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:52:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/11 12:47:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Les Includes
*/

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include "libft.h"

/*
** Les Typedefs
*/

typedef struct s_flag			t_flag;
typedef long long int			t_ll;
typedef unsigned long long int	t_ull;

struct		s_flag
{
	int		left;
	int		zero;
	int		width;
	int		precision;
	int		total_print;
	char	specifiers;
	t_ll	arg;
	t_ull	uarg;
	char	*s;
	wchar_t	*ls;
	char	arg_error;
};

/*
** Les fonctions qui récupèrent l'argument selon son type
*/

int			ft_printf(const char *restrict format, ...);
int			type_dispatch(const char *format, int i, va_list args);
int			flag_collect(const char *format, va_list args);

/*
**	Les fonctions de conversion.
*/

char		*convert_hexadecimal(void);
char		*convert_adress(char format);
int			size_unicode(wchar_t arg);
int			print_unicode(wchar_t arg, int nb_oct);

/*
** Les fonctions d'impression.
*/

char		*print_before(int nbr, char c, char *s, int *len);
char		*print_before_0x(int max, char c, char *s, int *len);
char		*print_before_sign(int max, char c, char *s, int *len);
char		*print_after(int nbr, char c, char *s, int *len);
void		print_hexa(char *s);
void		print_int(char *s);
int			print_character(void);
void		print_string(void);
void		print_string_unicode(void);
int			print_wchar(int nb_oct);
void		print_percent(void);

/*
** Les fonctions utiles modifiées pour printf.
*/

void		ft_putstr_fd_maxlen(char *s, int fd, unsigned int max);

extern	t_flag	*g_flag;

#endif
