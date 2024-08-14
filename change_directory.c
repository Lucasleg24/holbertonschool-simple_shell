#include "shell.h"

int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);

	if (chdir(path) == -1)
	{
		perror(path);
		return (-1);
	}

	return (1);
}
