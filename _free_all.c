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
	free(cmd_arg);
}

/**
 * ntty_free - free memory used by variables when ran in not
 * interactive mode.
 *
 * @pinput: pointer to memory used to store the user input
 * @cmd_arg: pointer to memory used to store the command arguments
 * @command: pointer to mermory used to store the command to exec
 * @env: pointer to mermory used to store environment PATH values
 * @exit_c: pointer to memory used to store exit codes
 */
void ntty_free(char **cmd_arg, char *command)
{
	  free(command);
	  free(cmd_arg);
}
