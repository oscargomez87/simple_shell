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
	char *pinput = NULL, *env = NULL, *command = NULL,
		*exit_c = NULL, *temp = NULL;
	char **cmd_arg;
	int file_access, cmd_count = 0;
	ssize_t cmd_len;

	env = _getenv("PATH");
	ecodeinit(&exit_c);
	cmd_len = _read(&pinput, &env, &cmd_count, exit_c);
	temp = pinput;
	while (cmd_len >= 0)
	{
		if (pinput == NULL)
			return;
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
		{
			pdeniederr(argv, exit_c);
			ntty_free(cmd_arg, command);
		} else if (file_access == 127)
		{
			nfounderr(argv, exit_c);
			ntty_free(cmd_arg, command);
		} else
			ntty_free(cmd_arg, command);
		cmd_len = _read(&pinput, &env, &cmd_count, exit_c);
	}
	free(temp);
	free(env);
	free(exit_c);
}
