#include "shs.h"

/**
 * _exec - receives command and arguments for command
 * then calls execve with those parameters
 *
 * @command: Command to execute with execve
 * @cmd_arg: Arguments for command to execute
 */
void _exec(char *command, char **cmd_arg, char *exit_c)
{
	char *command_exit = "exit";
	pid_t child_pid;
	int wait_status;

	if (strcmp(command, command_exit) == 0)
	{
		/*free(*env);
		free(*pinput);*/
		exit(atoi(*(cmd_arg + 1));
	}
	/*if (strcmp(*command, command_env) == 0 && cmd_arg)
			print_env(env);*/
	child_pid = fork();
	if (child_pid == -1)
		exit(1);
	if (child_pid == 0)
	{
		execve(command, cmd_arg, NULL);
	} else
	{
		wait(&wait_status);
		if (WIFEXITED(wait_status))
		{
			wait_status = WEXITSTATUS(wait_status);
			_itoa(wait_status, exit_c);
		}
	}
}

void _itoa(int wait_status, char *s)
{
	int i, status;

	status = wait_status;
	for (i = 0; status / 10 != 0; i++)
		status = status / 10;
	s[i + 1] = '\0';
	for (; i >= 0; i--)
	{
		s[i] = (wait_status % 10) + '0';
		wait_status = wait_status / 10;
	}
}
