#include "shs.h"

/**
 * token_command - Read command_line and return the first command.
 * @command_line: command line string.
 *
 * Return: string with the first command from command_line.
 */
char *token_command(char *command_line)
{
	int i = 0, command_size = 0;
	char *result = NULL;

	if (command_line == NULL)
		return (NULL);

	for (i = 0; command_line[i] != 32 && command_line[i] != '\0'; i++)
		command_size++;

	result = (char *) malloc((command_size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < command_size; i++)
		result[i] = command_line[i];

	result[command_size] = '\0';
	return (result);
}

/**
 * token_arguments - Reads STDIN then saves it in a pointer removing NL
 * @command_line: pointer to save string in.
 *
 * Return: void.
 */
void token_arguments(char *command_line, char *args_for_execve[])
{
	(void) command_line;
	args_for_execve[] = {"", NULL};
/*
	int i = 0, j = 0, number_of_tokens = 0;

	for (i = 0; (*command_line)[i] != '\0'; i++)
		if ((*command_line)[i] == 32)
			number_of_tokens++;


	if (command_line == NULL)
		return (NULL);

	result = malloc(height * sizeof(int *));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		result[i] = malloc(width * sizeof(int));
		if (result[i] == NULL)
		{
			for (j = 0; j <= i; j++)
				free(result[j]);
			free(result);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			result[i][j] = 0;

	return (result);
*/
}
