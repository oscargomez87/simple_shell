#include "shs.h"

void pdeniederr(char *argv, char *exit_c)
{
	fprintf(stderr, "%s: ", argv);
	perror("");
	strcpy(exit_c, "126");
}

void nfounderr(char *argv, char *exit_c)
{
	fprintf(stderr, "%s: ", argv);
	perror("");
	strcpy(exit_c, "127");
}
