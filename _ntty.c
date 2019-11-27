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
	char *pinput = NULL, *env = NULL, *command = NULL, *temp = NULL;
	char **cmd_arg;
	int file_access, cmd_count = 0;
	ssize_t cmd_len;

	env = _getenv("PATH");
	cmd_len = _read(&pinput, &env, &cmd_count);
	temp = pinput;
	while (cmd_len >= 0)
	{
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
		ntty_free(cmd_arg, command);
		cmd_len = _read(&pinput, &env, &cmd_count);
	}
	free(temp);
	free(env);
	exit(errno);
}
