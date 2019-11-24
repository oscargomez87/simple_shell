#include "shs.h"

/**
 * _exec - receives command and arguments for command
 * then calls execve with those parameters
 *
 * @command: Command to execute with execve
 * @cmd_arg: Arguments for command to execute
 */
void _exec(char *command, char **cmd_arg)
{
	pid_t child_pid;
	int wait_status;

	child_pid = fork();
	if (child_pid == -1)
		exit(1);
	if (child_pid == 0)
	{
		execve(command, cmd_arg, NULL);
	} else
		wait(&wait_status);
}
