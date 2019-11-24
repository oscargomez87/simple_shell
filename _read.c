#include "shs.h"

/**
 * _read - Reads STDIN then saves it in a pointer removing NL
 * @command_line: pointer to save string in.
 *
 * Return: void.
 */
void _read(char **command_line, char **env)
{
	int i = 0;
	char *command_exit = "exit", *command_env ="env";
	size_t len_of_command = 0;
	ssize_t len_of_read;

	len_of_read = getline(&(*command_line), &len_of_command, stdin);
	if (len_of_read == -1)
	{
		free(*env);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	for (i = 0; (*command_line)[i] != '\n'; i++)
		;
	(*command_line)[i] = '\0';
	if (*command_line[0] == '\0')
	{
		free(*command_line);
		*command_line = NULL;
		return;
	}
	if (strcmp(*command_line, command_exit) == 0)
	{
		free(*command_line);
		free(*env);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(*command_line, command_env) == 0)
        print_env(env);
}
