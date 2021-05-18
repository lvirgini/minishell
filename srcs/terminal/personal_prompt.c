/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personal_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:49:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 10:36:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* NOT USED CAN'T HAVE HOSTNAME ? 
static char		*add_sequence_to_prompt(int	sequence, char *old_prompt)
{
	static char	*sequence[] = { "USER", "HOST", "PWD", "PWD"};


}


static char		*add_ps1_to_prompt(int size, char *add, char *old_prompt)
{
	char	*ret;

	if (!old_prompt)
		ret = ft_strdup_max(add, size);
	else
	{
		ret = ft_strjoin_max(old_prompt, add, size);
		free(old_prompt);
	}
	return (ret);
	
}

char			*get_personal_prompt(char	*ps1)
{
	static char	*sequence[] = { "\\u", "\\h", "\\w", "\\W"};
	char		*prompt;
	int			seq;
	int			i;

	i = 0;
	while (*(ps1 + i) != '\0')
	{
		seq = 0;
		while (seq < 4 && ft_strcmp( sequence[seq], ps1[i]) != 0)
			seq++;
		if (seq < 4)
		{
			if (i != 0)
				prompt = add_ps1_to_prompt(i - 1, ps1, prompt);
			prompt = add_sequence_to_prompt(seq, prompt);
			ps1 += i;
			i = 0;
		}
		else
			i++;
	}
	if (i > 0)
		return (add_ps1_to_prompt(i, ps1, prompt));
	return (prompt);
}*/