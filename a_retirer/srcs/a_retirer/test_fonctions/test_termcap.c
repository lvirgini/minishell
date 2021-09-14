/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:22:10 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/13 14:34:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

int init_term()
{
    int ret;
    char *term_type = getenv("TERM");

    if (term_type == NULL)
    {
        fprintf(stderr, "TERM must be set (see 'env').\n");
        return -1;
    }
    ret = tgetent(NULL, term_type);

    if (ret == -1)
    {
        fprintf(stderr, "Could not access to the termcap database..\n");
        return -1;
    }
    else if (ret == 0)
    {
        fprintf(stderr, "Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_type);
        return -1;
    }
    return 0;
}

void	test_all_termcaps(void)
{
/*
	if (init_term() == -1)
		exit(EXIT_FAILURE);
	printf("li = %d\n", tgetnum("li"));
	printf("col = %d\n", tgetnum("col"));
	printf("row = %d\n", tgetnum("row"));	
	printf("name = %d\n", tgetnum("name"));

	struct termios t;
	struct termios backup;

	if (tcgetattr(STDIN_FILENO, &backup) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(STDIN_FILENO, &t) == -1)
		exit(EXIT_FAILURE);

	t.c_cflag &= ~(ICANON);

	tcsetattr(STDIN_FILENO, 0, &t);

	char	*buf = malloc(sizeof(char) * 256);
	if (buf == NULL)
		exit(EXIT_FAILURE);
	char *cl_cap;

	while (read(0, buf, 256))
	{
		//if (ft_strncmp(buf, tgetnum("a"), ft_strlen(buf)))
		
		cl_cap = tgetstr("cl", NULL);
		tputs (cl_cap, 1, putchar);

	}
	free(buf);

	tcsetattr(STDIN_FILENO, 0, &backup);*/
}