#ifndef SHELL_H
#define SHELL_H

/*
 * ----------------------------------
 *		INCLUSIONS
 * ----------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern int exit_value;

/*
 * ----------------------------------
 *		ENTRY POINT
 * ----------------------------------
 */

int main(int argc, char **argv, char **envp);
void non_interactive_mode(char **envp);

/*
 *  ----------------------------------
 *	USER INPUT MANAGEMENT
 *  ----------------------------------
 */

void sigint(int sig);
char *input(const char *text);
char **parse(char *buffer, const char *str);

/*
 * ----------------------------------
 *	METHOD ACCESS / EXECUTION
 * ----------------------------------
 */

char *buildPath(char **envp);
char *get_location(char *command, char **envp);
void execute(char **command, char **envp);
void check_pid( char *actual_command, char **command,int status, pid_t pid, char **envp);

/*
 * ----------------------------------
 *		PROCESS
 * ----------------------------------
 */

int process_command(char **args, char **envp, char *line);
int change_dir(const char *path);
void print_env(char **env);
void print_history(const char *command);

/*
 * ----------------------------------
 *		CLEANERS
 * ----------------------------------
 */

void free_history(void);
void free_continue(char **command);
void shell_exit(char *line, char **args, int exit_value);

#endif /* SHELL_H */
