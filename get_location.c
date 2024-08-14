#include "shell.h"

/**
 * get_location - search the path of the command
 * @command: string with argument
 * @envp: array with pointer
 * Return: return the file path or error
 */

char *get_location(char *command, char **envp)
{
	char *path = NULL, *path_copy = NULL, *path_token = NULL, *file_path = NULL;
	int command_length, directory_length;
	struct stat buffer;

	path_copy = strdup(buildPath(envp, path));
	if (path_copy == NULL)
		return (NULL);

	command_length = strlen(command);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		directory_length = strlen(path_token);
		file_path = malloc(command_length + directory_length + 2);

		if (file_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);

		if (stat(file_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (file_path);
		}

		free(file_path);
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
