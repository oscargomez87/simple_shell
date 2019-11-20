#include "shs.h"

/**
 * _itty - Interactive, waits for input then calls program if it is found.
 *
 * @argv: parameters received from main(), name of the application.
 */
void _itty(char *argv)
{
	char *command_line = NULL, *env = NULL;
	int file_access = -1;

	while (1)
	{
		printf("#MiniShell$ ");
		if (env == NULL)
			env = _getenv("PATH");
		_read(&command_line, &env);
		if (command_line == NULL)
			continue;
		file_access = _findcmd(&command_line, argv, env);
		if (file_access == 0)
		{
			file_access = access(command_line, X_OK);
			if (file_access == 0)
			{
				_exec(command_line);
			} else
				printf("%s: %s: Permission denied\n",
				       argv, command_line);
		}
		free(command_line);
	}
}
