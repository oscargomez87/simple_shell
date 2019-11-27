#include "shs.h"

/**
 * _exec - receives command and arguments for command
 * then calls execve with those parameters
 *
 * @command: Command to execute with execve
 * @cmd_arg: Arguments for command to execute
 * @cmd_count: keeps track of number of commands executed
 */
void _exec(char *command, char **cmd_arg, int *cmd_count)
{
	int wait_status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		exit(1);
	if (child_pid == 0)
	{
		execve(command, cmd_arg, environ);
		ntty_free(cmd_arg, command);
	} else
	{
		wait(&wait_status);
		(*cmd_count)++;
		if (WIFEXITED(wait_status))
		{
			wait_status = WEXITSTATUS(wait_status);
		}
	}
	if (child_pid == 0)
		_exit(0);
}
