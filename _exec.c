#include "shs.h"

/**
 * _exec - receives command and arguments for command
 * then calls execve with those parameters
 *
 * @command: Command to execute with execve
 * @cmd_arg: Arguments for command to execute
 * @exit_c: keeps track of command execution exit code
 * @cmd_count: keeps track of number of commands executed
 */
void _exec(char *command, char **cmd_arg, char *exit_c, int *cmd_count)
{
	int wait_status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		exit(1);
	if (child_pid == 0)
	{
		execve(command, cmd_arg, NULL);
		free(command);
		free(*cmd_arg);
		free(exit_c);
	} else
	{
		wait(&wait_status);
		(*cmd_count)++;
		if (WIFEXITED(wait_status))
		{
			wait_status = WEXITSTATUS(wait_status);
			_itoa(wait_status, exit_c);
		}
	}
}
