#include "shs.h"

/**
 * _read - Reads STDIN then saves it in a pointer removing NL
 *
 * @pinput: pointer to save string in.
 * @env: pointer to string with PATH values
 * @cmd_count: Commands issued counter
 * Return: void.
 */
ssize_t _read(char **pinput, char **env, int *cmd_count)
{
	char *command_exit = "exit", *command_env = "env";
	size_t input_len = 0;
	ssize_t cmd_len;

	cmd_len = getline(&(*pinput), &input_len, stdin);
	if (cmd_len == -1)
	{
		free(*pinput);
		(*cmd_count)++;
		return (cmd_len);
	}
	(*pinput)[cmd_len - 1] = '\0';
	if (_strcmp(*pinput, command_exit) == 0)
	{
		free(*env);
		free(*pinput);
		(*cmd_count)++;
		exit(errno);
	}
	if (_strcmp(*pinput, command_env) == 0)
	{
		(*cmd_count)++;
		return (-1);
	}
	return (cmd_len);
}
