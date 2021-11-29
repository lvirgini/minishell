/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_return.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:55:36 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/29 13:28:43 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_RETURN_H
# define MINISHELL_RETURN_H

unsigned char	set_exit_status(int exit_status, int get);
unsigned char	set_exit_value(int exit_value);
unsigned char	get_exit_status(void);
unsigned char	get_exit_value(void);

typedef struct s_return_value
{
	unsigned char	status;
	t_bool			value;
}				t_return_value;

#endif