#include "shs.h"

char *_read(char **command_line);
void _narg(void);

int main(void)
{
	_narg();
        return (0);
}

char *_read(char **command_line)
{
	size_t len_of_command = 0;
	ssize_t len_of_read;

	printf("#MiniShell$ ");
	len_of_read = getline(&(*command_line), &len_of_command, stdin);
	if (len_of_read == -1)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	return (*command_line);
}

void _narg(void)
{
	char *command_line = NULL;
        char *command_exit = "exit";
	char *args_for_execve[] = { "", NULL}, *new_env_vars[] = { NULL };
	int i = 0, file_ok, wait_status;
        pid_t child_pid;

	while (1)
        {
		_read(&command_line);
		for(i = 0; command_line[i] != '\n'; i++)
			;
		command_line[i] = '\0';
		if(strcmp(command_line, command_exit) == 0)
			exit(EXIT_SUCCESS);
		file_ok = access(command_line, F_OK | X_OK);
		if(file_ok >= 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				exit(1);
			if (child_pid == 0)
			{
				execve(command_line, args_for_execve,
				       new_env_vars);
				free(command_line);
			} else
				wait(&wait_status);
		}
	}
}
