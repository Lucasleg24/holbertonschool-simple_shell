#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp);
char *input(const char *text);
char **parse(char *buffer, const char *str);
char *get_location(char *command, char **envp);
char *buildPath(char **envp);
void execute(char **command, char **envp);
int change_dir(const char *path);
void print_env(char **env);
void free_continue(char **command);
void shell_exit(char *line, char **args);
void sigint(int sig);

#endif
