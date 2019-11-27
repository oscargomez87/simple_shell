#include "shs.h"

/**
 * _read - Reads STDIN then saves it in a pointer removing NL
 *
 * @pinput: pointer to save string in.
 * @env: pointer to string with PATH values
 * @cmd_count: Commands issued counter
 * @exit_c: Variable that stores exit codes
 * Return: void.
 */
void _read(char **pinput, char **env, int *cmd_count, char *exit_c)
{
	char *command_exit = "exit", *command_env = "env";
	ssize_t cmd_len;

	cmd_len = 0;
	if (cmd_len == -1)
	{
		free(*env);
		free(exit_c);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	if (cmd_len == 1)
	{
		free(*pinput);
		*pinput = NULL;
		return;
	}
	(*pinput)[cmd_len - 1] = '\0';
	if (strcmp(*pinput, command_exit) == 0)
	{
		free(exit_c);
		free(*env);
		free(*pinput);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(*pinput, command_env) == 0)
	{
		print_env();
		(*cmd_count)++;
	}
}
