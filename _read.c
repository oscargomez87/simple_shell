#include "shs.h"

/**
 * _read - Reads STDIN then saves it in a pointer removing NL
 *
 * @pinput: pointer to save string in.
 * @env: pointer to string with PATH values
 * Return: void.
 */
void _read(char **pinput, char **env)
{
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
}
