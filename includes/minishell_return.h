/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_return.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:55:36 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/26 08:14:46 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_RETURN
# define MINISHELL_RETURN

unsigned char	set_exit_status(int exit_status);
unsigned char	set_exit_value(int exit_value);
unsigned char	get_exit_status(void);
unsigned char	get_exit_value(void);

#endif