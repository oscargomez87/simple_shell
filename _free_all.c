#include "shs.h"

/**
 * _free_all - free memory used by variables
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

void ntty_free(char *pinput, char **cmd_arg,
	       char *command, char *env, char *exit_c)
{
	free(exit_c);
	free(env);
	free(pinput);
	free(command);
	free(cmd_arg);
}
