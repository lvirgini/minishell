/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:51:16 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/10 15:53:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	testing_prompt(t_env **env)
{
	t_prompt *prompt;

	prompt = get_prompt(env, NULL);
	printf("formatted = %s\n", prompt->formatted);
	remove_t_env(env, "USER");
	prompt = get_prompt(env, prompt);
	printf("formatted = %s\n", prompt->formatted);
	edit_or_add_t_env(env, "USER", "user2eme");
	prompt = get_prompt(env, prompt);
	printf("formatted = %s\n", prompt->formatted);
	print_this_env(get_this_env(env, "USER"));
	//printer_prompt(prompt);
}