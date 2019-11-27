#include "shs.h"

/**
 * _itty - Interactive, waits for input then calls program if it is found.
 *
 * @argv: parameters received from main(), name of the application.
 */
void _itty(char *argv)
{
	char *pinput = NULL, *env = NULL, *command = NULL;
	char **cmd_arg;
	int file_access, cmd_count = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (env == NULL)
			env = _getenv("PATH");
		_read(&pinput, &env, &cmd_count);
		if (pinput == NULL)
		{
			perror(argv);
			continue;
		}
		trimspaces(&pinput);
		command = token_command(pinput);
		cmd_arg = token_arguments(pinput);
		file_access = _findcmd(&command, env);
		if (file_access == 0)
		{
			file_access = access(command, X_OK);
			if (file_access == 0)
				_exec(command, cmd_arg, &cmd_count);
			else
				perror(argv);
		} else
			perror(argv);
		itty_free(pinput, cmd_arg, command);
	}
}
