#include "shs.h"

/**
 * _read - Reads STDIN then saves it in a pointer removing NL
 *
 * @pinput: pointer to save string in.
 * @env: pointer to string with PATH values
 * Return: void.
 */
void _read(char **pinput, char **env, char *exit_c)
{
	char *command_exit = "exit", *command_env = "env";
	size_t input_len = 0;
	ssize_t cmd_len;

	cmd_len = getline(&(*pinput), &input_len, stdin);
	if (cmd_len == -1)
	{
		free(*env);
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
		free(*env);
		free(*pinput);
		free(exit_c);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(*pinput, command_env) == 0)
		print_env(env);
}
