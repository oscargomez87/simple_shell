#include "shs.h"

/**
 * _itty - Interactive, waits for input then calls program if it is found.
 *
 * @argv: parameters received from main(), name of the application.
 */
void _itty(char *argv)
{
	char *pinput = NULL, *env = NULL, *command = NULL, *exit_c = NULL;
	char **cmd_arg;
	int file_access, cmd_count = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (env == NULL)
			env = _getenv("PATH");
		if (exit_c == NULL)
			ecodeinit(&exit_c);
		_read(&pinput, &env, &cmd_count, exit_c);
		if (pinput == NULL)
			continue;
		trimspaces(&pinput);
		command = token_command(pinput);
		cmd_arg = token_arguments(pinput, exit_c);
		file_access = _findcmd(&command, env);
		if (file_access == 0)
		{
			file_access = access(command, X_OK);
			if (file_access == 0)
				_exec(command, cmd_arg, exit_c, &cmd_count);
		}
		if (file_access == -1)
			pdeniederr(argv, exit_c);
		else if (file_access == 127)
			nfounderr(argv, exit_c);
		itty_free(pinput, cmd_arg, command);
	}
}
