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
	char *command_line = NULL, *env = NULL;
	char *args_for_execve[] = { "", NULL}, *new_env_vars[] = { NULL };
	int file_access = -1;

	env = _getenv("PATH");
	_read(&command_line, &env);
	if (command_line == NULL)
		return;
	file_access = _findcmd(&command_line, argv, env);
	if (file_access == 0)
	{
		file_access = access(command_line, X_OK);
		if (file_access == 0)
		{
			execve(command_line, args_for_execve, new_env_vars);
			free(command_line);
		}
		else
			printf("-%s: %s: Permission denied\n",
			       argv, command_line);
	}
	free(command_line);
}
