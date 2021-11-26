/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/26 17:38:29 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	display_error(int error, char *object)
{
	static char	*str_error[NB_ERROR] = {
		"\n",
		": command not found\n",
		": permission denied\n",
		": No such file or directory\n",
		": ambiguous redirect\n",
		": Is a directory\n"
	};
	static int	errno_nb[NB_ERROR] = {1, 127, 126, 127, 126, 126};

	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error < NB_ERROR)
	{
		ft_putstr_fd(object, STDERR_FILENO);
		ft_putstr_fd(str_error[error], STDERR_FILENO);
		set_exit_status(errno_nb[error], 0);
	}
	else
	{
		perror(object);
		set_exit_status(1, 0);
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
	exit(get_exit_status());
}
