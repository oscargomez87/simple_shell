#include "shs.h"

/**
 * _getpath - checks if user input can be found in the PATH,
 * then stores it
 *
 * @fullcommand: temp variable to store the PATH + command
 * @env_token: variable to store separated path directories
 * @command: command entered by user
 * Return: 0 if command is found in directory path, -1 otherwise
 */
int _getpath(char **fullcommand, char *env_token, char **command)
{
	while (env_token != NULL)
	{
		*fullcommand = malloc(strlen(*command)
				 + strlen(env_token) + 2);
		if (*fullcommand == NULL)
		{
			return (-1);
		}
		strcpy(*fullcommand, env_token);
		strcat(*fullcommand, "/");
		strcat(*fullcommand, *command);
		if (access(*fullcommand, F_OK) == 0)
		{
			free(*command);
			*command = *fullcommand;
			return (0);
		}
		free(*fullcommand);
		env_token = strtok(NULL, ":");
	}
	return (-1);
}
