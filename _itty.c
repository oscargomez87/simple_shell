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
	int file_access, errorc = 0;

	while (1)
	{
		printf("$ ");
		if (env == NULL)
			env = _getenv("PATH");
		_read(&pinput, &env);
		if (pinput == NULL)
			continue;
		command = token_command(pinput);
		cmd_arg = token_arguments(pinput);
		file_access = _findcmd(&command, argv, env, &errorc);
		if (file_access == 0)
		{
			file_access = access(command, X_OK);
			if (file_access == 0)
			{
				_exec(command, cmd_arg);
			} else
			{
				errorc++;
				printf("%s: %d: %s: Permission denied\n",
				       argv, errorc, command);
			}
		} else if (file_access == -1)
		{
			errorc++;
			printf("%s: %d: %s: Permission denied\n",
			       argv, errorc, command);
		}
		_free_all(pinput, cmd_arg, command);
	}
}
