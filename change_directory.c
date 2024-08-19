#include "shell.h"

/**
 * change_dir - Function to change directory
 *
 * @path: The way to the new directory
 *
 * Return: 1 or -1
 */

int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
	{
		buf = getcwd(buf, size);
		if (buf == NULL)
		{
			perror("getcwd");
			return (-1);
		}
		path = buf;
	}

	if (chdir(path) == -1)
	{
		perror(path);
		free(buf);
		return (-1);
	}

	free(buf);
	return (1);
}
