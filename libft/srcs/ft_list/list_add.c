/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:37:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 19:54:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_list_add_one(char **list, char *to_add)
{
    char **result;
    size_t  list_len;

    list_len = listlen(list) + 1;
    result = malloc_list(list_len);
    if (!result)
    {
        free_list(list);
        free(to_add);
        return (NULL);
    }
    list_move(result, list);
    result[list_len] = ft_strdup(to_add);
    result[list_len + 1] = NULL;
    free(list);
    free(to_add);
    return (result);
}
