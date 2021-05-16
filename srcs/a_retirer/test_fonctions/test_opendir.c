#include "test_minishell.h"
#include <dirent.h>
#include <string.h>

void	test_opendir(void)
{
	DIR 			*dir;
	struct dirent	*file;
	char			*path;

	path = "/home/mini/42/minishell/srcs/a_retirer";
	dir = opendir(path);
	if (dir == NULL)
	{
		perror(path);
		exit(EXIT_FAILURE);
	}
	file = readdir(dir);
	while (file != NULL)
	{
		printf("file = %s\n", file->d_name);
		file = readdir(dir);
	}
	closedir(dir);
}
