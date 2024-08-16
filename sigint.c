#include "shell.h"

void sigint(int sig)
{
	(void)sig;
	putchar('\n');
}
