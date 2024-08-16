#include "shell.h"

void end_of_file(char *buf)
{
	free(buf);

	if (buf)
		buf = NULL;

	exit(EXIT_SUCCESS);
}
