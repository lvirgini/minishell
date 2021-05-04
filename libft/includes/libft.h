/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 00:09:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/03 17:30:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "ft_printf.h"
# include "ft_maths.h"
# include "ft_vector.h"
# include "ft_list.h"

/*
** Global Usage
*/

enum e_bool
{
	false,
	true,
};

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

/*
** Fonctions verifiant si l'argument donné est bien quelque chose
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** Fonctions d'impression et ou de conversion
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char *s);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_base_fd(int nbr, char *base, int fd);
void			ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *s);
int				ft_atoi_base(char *str, char *base);
double			ft_atof(const char *str);
int				ft_atoi_i(const char *s, int *result);
int				ft_atof_i(const char *str, double *result);
char			*ft_itoa(int n);
char			*ft_lltoa(long long int n);
char			*ft_utoa(unsigned int n);
char			*ft_ulltoa(unsigned long long int n);

/*
** Fonction dl'allocation de mémoire
*/

void			*ft_calloc(size_t count, size_t size);

/*
** Fonctions traitant les zones mémoires
*/

void			*ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Fonctions traitant les strings
*/

size_t			ft_strlen(const char *s);
size_t			ft_strlen_set(const char *s, const char *set);
int				ft_strchr_len(const char *s, int c);
char			*ft_strchr_set(const char *s, const char *set);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strdup(const char *s);
char			*ft_strdup_max(const char *s, size_t max);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strcut(char *s, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s, char const *set);
char			**ft_split(char const *s, const char c);
char			**ft_split_set(char const *s, const char *set);
char			**ft_split_count(const char *s, const char c, size_t *size);
void			ft_free_split_str(char **str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
