#include "shs.h"

int _findcmd(char **command_line, char *argv)
{
	char *env, *env_token, *command = *command_line;

	if (access(*command_line, F_OK) == 0)
		return (0);
	env = _getenv("PATH");
	env_token = strtok(env, ":");
	while (env_token != NULL)
	{
		*command_line = malloc(strlen(command)
				       + strlen(env_token) + 1);
		strcpy(*command_line, env_token);
		strcat(*command_line, "/");
		strcat(*command_line, command);
		if (access(*command_line, F_OK) == 0)
			return (0);
		env_token = strtok(NULL, ":");
	}
	*command_line = command;
	printf("-%s: %s: No such file or directory\n",
	       argv, *command_line);
	return (-1);
}
