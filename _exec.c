#include "shs.h"

void _exec( char *command_line)
{
	char *args_for_execve[] = { "", NULL}, *new_env_vars[] = { NULL };
	pid_t child_pid;
	int wait_status;

	child_pid = fork();
	if (child_pid == -1)
		exit(1);
	if (child_pid == 0)
	{
		execve(command_line, args_for_execve,
		       new_env_vars);
	} else
		wait(&wait_status);
}
