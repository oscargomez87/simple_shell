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
char **token_arguments(char *command_line)
{
	int i = 0, number_of_tokens = 0;
	const char s[7] = " \t\r\n\v\f";
	char **result;

	if (command_line == NULL)
		return (NULL);

	for (i = 0; command_line[i] != '\0'; i++)
		if (command_line[i] == 32)
			number_of_tokens++;

	if (number_of_tokens == 0)
	{
		result = malloc(2 * sizeof(char *));
		if (result == NULL)
			return (NULL);
		result[0] = malloc(1 * sizeof(char *));
		result[1] = malloc(1 * sizeof(char *));
		result[0] = "";
		result[1] = NULL;
		return (result);
	}
	else
	{
		result = malloc((number_of_tokens + 2) * sizeof(char *));
		if (result == NULL)
			return (NULL);

		result[0] = strtok(command_line, s);
		/*result[0] = "";*/
		for (i = 0; result[i] != NULL; i++)
			result[i + 1] = strtok(NULL, s);
		/*result[number_of_tokens + 1] = NULL;*/
		return (result);
	}
}
