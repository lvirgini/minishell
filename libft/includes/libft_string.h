/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:28:09 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 10:43:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include "libft.h"

/*
** Fonctions traitant les strings
*/

size_t	ft_strlen(const char *s);
size_t	ft_strlen_set(const char *s, const char *set);
size_t	ft_strchr_set_len(const char *s, const char *set);
int		ft_strchr_len(const char *s, int c);
char	*ft_strchr_set(const char *s, const char *set);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strdup_max(const char *s, size_t max);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcut(char *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	**ft_split(char const *s, const char c);
char	**ft_split_set(const char *s, const char *set);
void	free_list_exit(char **list);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
