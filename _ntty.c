#include "shs.h"

/**
 * _ntty - non-interactive. Receives input, calls the program then exits
 *
 * @argv: arguments passed, name of executable file.
 *
 * Return: void
 */
void _ntty(char *argv)
{
	char *pinput = NULL, *env = NULL, *command = NULL, *exit_c = NULL;
	char **cmd_arg;
	int file_access, errorc = 0;

	env = _getenv("PATH");
	exit_c = malloc(4 * sizeof(char));
	exit_c[0] = 0 + '0';
	exit_c[1] = '\0';
	_read(&pinput, &env, exit_c);
	if (pinput == NULL)
		return;
	command = token_command(pinput);
	cmd_arg = token_arguments(pinput, exit_c);
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
			free(exit_c);
			free(env);
			_free_all(pinput, cmd_arg, command);
			exit(126);
		}
	} else if (file_access == -1)
	{
		errorc++;
		printf("%s: %d: %s: Permission denied\n",
		       argv, errorc, command);
		free(exit_c);
		free(env);
		_free_all(pinput, cmd_arg, command);
		exit(126);
	} else if (file_access == 127)
	{
		free(exit_c);
		free(env);
		_free_all(pinput, cmd_arg, command);
		exit(127);
	}
	if (exit_c != 0)
		exit(atoi(exit_c));
}
