#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void);
char* input(const char *text);
char **parse(char *buffer, const char *str);

#endif
