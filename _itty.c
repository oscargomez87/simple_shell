#include "shs.h"

/**
 * _itty - Interactive, waits for input then calls program if it is found.
 *
 * @argv: parameters received from main(), name of the application.
 */
void _itty(char *argv)
{
	char *command_line = NULL, *env = NULL, *command_for_execve = NULL;
	char **arguments_for_execve;
	int file_access = -1;

	while (1)
	{
		printf("#MiniShell$ ");
		if (env == NULL)
			env = _getenv("PATH");
		_read(&command_line, &env);
		if (command_line == NULL)
			continue;
		command_for_execve = token_command(command_line);
		arguments_for_execve = token_arguments(command_line);
		free(command_line);
		file_access = _findcmd(&command_for_execve, argv, env);
		if (file_access == 0)
		{
			file_access = access(command_for_execve, X_OK);
			if (file_access == 0)
			{
				_exec(command_for_execve,
				  arguments_for_execve);
			} else
			{
				printf("%s: %s: Permission denied\n",
				       argv, command_for_execve);
			}
		}
		free(command_for_execve);
		free(arguments_for_execve);
	}
}
