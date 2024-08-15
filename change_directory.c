#include "shell.h"

/**
 * change_dir - use cd
 * @path: path for cd
 * Return: return error or success value
 */

int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);

	if (chdir(path) == -1)
	{
		perror(path);
		free(buf);
		return (-1);
	}

	free(buf);
	return (1);
}
