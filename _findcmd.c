#include "shs.h"

int _findcmd(char **command_line, char *argv)
{
	char *env, *env_token, *command = NULL;

	if (access(*command_line, F_OK) == 0)
		return (0);
	env = _getenv("PATH");
	env_token = strtok(env, ":");
	while (env_token != NULL)
	{
		command = malloc(strlen(*command_line)
				       + strlen(env_token) + 2);
		strcpy(command, env_token);
		strcat(command, "/");
		strcat(command, *command_line);
		if (access(command, F_OK) == 0)
		{
			free(*command_line);
			*command_line = command;
			return (0);
		}
		free(command);
		env_token = strtok(NULL, ":");
	}
	printf("-%s: %s: No such file or directory\n",
	       argv, *command_line);
	return (-1);
}
