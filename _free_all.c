#include "shs.h"

/**
 * itty_free - free memory used by variables when ran in interactive mode
 *
 * @pinput: pointer to memory used to store the user input
 * @cmd_arg: pointer to memory used to store the command arguments
 * @command: pointer to mermory used to store the command to exec
 */
void itty_free(char *pinput, char **cmd_arg, char *command)
{
	free(pinput);
	free(command);
	freepcontent(cmd_arg);
}

/**
 * ntty_free - free memory used by variables when ran in not
 * interactive mode.
 *
 * @cmd_arg: pointer to memory used to store the command arguments
 * @command: pointer to mermory used to store the command to exec
 */
void ntty_free(char **cmd_arg, char *command)
{
	free(command);
	freepcontent(cmd_arg);
}

/**
 * freepcontent - Iterates array of pointers and frees the memory
 *
 * @cmd_arg: array of pointers to iterate and free
 */
void freepcontent(char **cmd_arg)
{
	int i = 0;

	while (cmd_arg[i] != NULL)
	{
		free(cmd_arg[i]);
		i++;
	}
	free(cmd_arg);
}
