#include "shell.h"

char *get_location(char *command, char **envp)
{
	char *path = NULL, *path_copy = NULL, *path_token = NULL, *file_path = NULL;
	int command_length, directory_length, i;
	struct stat buffer;

	/* Rechercher la variable PATH dans envp */
	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			/* Obtenir la valeur de PATH ( le "+5" enleve "PATH=" */
			path = envp[i] + 5;
			break;
		}
	}

	if (path == NULL)
		return (NULL);

	/* Dupliquer la chaîne de chemin pour ne pas modifier le PATH reel avec strtok*/
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	command_length = strlen(command);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		directory_length = strlen(path_token);

		/* Allouer de la mémoire pour stocker le nom de la commande et le répertoire */
		file_path = malloc(command_length + directory_length + 2);
		if (file_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		/* Construire le chemin complet */
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);

		/* Vérifier si le fichier existe et est exécutable */
		if (stat(file_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (file_path);
		} else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}

	free(path_copy);
	return (NULL);
}
