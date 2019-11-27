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
	char *pinput = NULL, *env = NULL, *command = NULL, __attribute__((unused))*exit_c = NULL, *temp = NULL;
	char **cmd_arg;
	int file_access, cmd_count = 0, __attribute__((unused))e_code, i;
	size_t input_len = 0;
	ssize_t cmd_len;

	env = _getenv("PATH");
	ecodeinit(&exit_c);
	cmd_len = getline(&pinput, &input_len, stdin);
	temp = pinput;
	while ( cmd_len >= 0)
	{
		if (pinput == NULL)
			return;
		for (i = 0; pinput[i] != '\n'; i++)
			;
		pinput[i] = '\0';
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
			pdeniederr(&cmd_count, argv, command, exit_c);
			ntty_free(cmd_arg, command);
			exit(126);
		} else if (file_access == 127)
		{
			nfounderr(&cmd_count, argv, command, exit_c);
			ntty_free(cmd_arg, command);
			exit(127);
		}else
		{
			e_code  = atoi(exit_c);
			ntty_free(cmd_arg, command);
		}
		cmd_len = getline(&pinput, &input_len, stdin);
	}
	free(temp);
	free(env);
	free(exit_c);
/*	exit(e_code);*/
}
