#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp);
char *input(const char *text);
char **parse(char *buffer, const char *str);
char *get_location(char *command, char **envp);
char *buildPath(char **envp, char *path);
void execute(char **command, char **envp);

#endif
