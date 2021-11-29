/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 13:30:55 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

int	display_error(int error, char *object)
{
	static char	*str_error[NB_ERROR] = {
		"\n",
		": command not found\n",
		": permission denied\n",
		": No such file or directory\n",
		": ambiguous redirect\n",
		": Is a directory\n",
		"error stdin_fileno not referring to a terminal\n"
	};
	static int	errno_nb[NB_ERROR] = {1, 127, 126, 127, 126, 126, 1};

	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error < NB_ERROR)
	{
		if (object)
			ft_putstr_fd(object, STDERR_FILENO);
		ft_putstr_fd(str_error[error], STDERR_FILENO);
		g_exit.status = errno_nb[error];
	}
	else
	{
		perror(object);
		g_exit.status = 1;
	}	
	return (errno);
}

void	display_heredoc_error(char *delimitor)
{
	ft_putstr_fd("minishell: warning: here-document delimited by \
end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delimitor, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}

void	exit_minishell(t_cmd **list_cmd, char **env)
{
	free_list_cmd(list_cmd);
	free_list(env);
	exit(g_exit.status);
}
