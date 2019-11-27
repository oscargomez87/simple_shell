#include "shs.h"

/**
 * token_command - Read command_line and return the first command.
 * @command_line: command line string.
 *
 * Return: string with the first command from command_line.
 */
char *token_command(char *command_line)
{
	int i, j, command_size = 0;
	const char delimit[7] = " \t\r\n\v\f";
	char *result = NULL;

	for (i = 0; command_line[i] != '\0'; i++)
	{
		for (j = 0; delimit[j] != '\0'; j++)
		{
			if (command_line[i] == delimit[j])
				break;
		}
		if (delimit[j] == '\0')
			command_size++;
		else
			break;
	}

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
 *
 * @command_line: pointer to save string in.
 * @exit_c: pointer to string with exit code
 * @ppid: pointer to string with process ID
 * Return: pointer to array of pointers.
 */
char **token_arguments(char *command_line, char *exit_c, char *ppid)
{
	int i = 0, number_of_tokens = 0;
	char *exvar = "$?", *pidvar = "$$", *temp;
	const char s[7] = " \t\r\n\v\f";
	char **result;

	for (i = 0; command_line[i] != '\0'; i++)
		if (command_line[i] == 32)
			number_of_tokens++;
	result = malloc((number_of_tokens + 2) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result[0] = _strdup(strtok(command_line, s));
	for (i = 0; result[i] != NULL; i++)
	{
		result[i + 1] = _strdup(strtok(NULL, s));
		if (result[i + 1] != NULL)
		{
			if (_strcmp(result[i + 1], exvar) == 0)
			{
				free(result[i + 1]);
				result[i + 1] = _strdup(exit_c);
			} else if (_strcmp(result[i + 1], pidvar) == 0)
			{
				free(result[i + 1]);
				result[i + 1] = _strdup(ppid);
			} else if (result[i + 1][0] == '$')
			{
				temp = result[i + 1];
				result[i + 1] = _getenv(&result[i + 1][1]);
				free(temp);
			}
		}
	}
	return (result);
}
