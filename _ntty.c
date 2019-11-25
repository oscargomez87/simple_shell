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
	char *pinput = NULL, *env = NULL, *command = NULL;
	char **cmd_arg;
	int file_access, errorc = 0;

	env = _getenv("PATH");
	_read(&pinput, &env);
	if (pinput == NULL)
		return;
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
	free(env);
	_free_all(pinput, cmd_arg, command);
}
