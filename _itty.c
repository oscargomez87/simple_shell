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
		cmd_arg = token_arguments(pinput, exit_c);
		exit_c = malloc(4 * sizeof(char));
		file_access = _findcmd(&command, argv, env, &errorc);
		if (file_access == 0)
		{
			file_access = access(command, X_OK);
			if (file_access == 0)
			{
				_exec(command, cmd_arg, exit_c);
			} else
			{
				errorc++;
				printf("%s: %d: %s: Permission denied\n",
				       argv, errorc, command);
				exit_c = "126";
			}
		} else if (file_access == -1)
		{
			errorc++;
			printf("%s: %d: %s: Permission denied\n",
			       argv, errorc, command);
			exit_c = "126";
		} else if (file_access == 127)
			exit_c = "127";
		_free_all(pinput, cmd_arg, command);
	}
}
