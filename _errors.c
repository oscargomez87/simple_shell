#include "shs.h"

void pdeniederr(int *cmd_count, char *argv, char *command,
		__attribute__((unused)) char *exit_c)
{
	cmd_count++;
	printf("%s: %d: %s: Permission denied\n", argv, *cmd_count, command);
	strcpy(exit_c, "126");
}

void nfounderr(int *cmd_count, char *argv, char *command,
	       __attribute__((unused)) char *exit_c)
{
	cmd_count++;
	printf("%s: %d: %s: not found\n", argv, *cmd_count, command);
	strcpy(exit_c, "127");
}
