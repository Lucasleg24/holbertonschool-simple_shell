#include "shell.h"

/**
 * parse_non_interactive - Change the string into token for
 * non_interactive mode
 *
 * @buffer: The buffer
 * @str: The delimiter
 *
 * Return: The tokenized command
 */

char **parse_non_interactive(char *buffer, const char *str)
{
    	char **commands;
    	char *token;
    	int i = 0, j;
    	int in_quotes = 0, cmd_count = 0;
    	int buf_len = strlen(buffer);

	(void)str;
    /* Count the number of commands (quoted strings)*/
    for (j = 0; j < buf_len; j++) {
        if (buffer[j] == '"')
            in_quotes = !in_quotes;
        else if (!in_quotes && buffer[j] == ' ' && j > 0 && buffer[j-1] == '"')
            cmd_count++;
    }
    cmd_count++; /* For the last command */

    commands = malloc((cmd_count + 1) * sizeof(char *));
    if (commands == NULL) {
        perror("Unable to allocate buffer");
        return NULL;
    }

    in_quotes = 0;
    token = buffer;
    for (j = 0; j <= buf_len; j++) {
        if (buffer[j] == '"') {
            in_quotes = !in_quotes;
            if (!in_quotes) { /* End of a quoted string*/
                buffer[j] = '\0';
                commands[i] = strdup(token + 1); /* +1 to skip opening quote*/
                if (commands[i] == NULL) {
                    perror("Unable to allocate buffer");
                    free_continue(commands);
                    return NULL;
                }
                i++;
                token = buffer + j + 1;
            }
        }
    }

    commands[i] = NULL;
    return commands;
}
