#include "shs.h"

void pdeniederr(char *argv, char *exit_c)
{
	perror(argv);
	strcpy(exit_c, "126");
}

void nfounderr(char *argv, char *exit_c)
{
	perror(argv);
	strcpy(exit_c, "127");
}
