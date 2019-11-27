#include "shs.h"

/**
 * pdeniederr - writes to stderr and stores a copy of the error code
 *
 * @argv: string with the name of the shell
 * @exit_c: string to store the error code
 **/
void pdeniederr(char *argv, char *exit_c)
{
	perror(argv);
	_strcpy(exit_c, "126");
}

/**
 * nfounderr - writes to stderr and stores a copy of the error code
 *
 * @argv: string with the name of the shell
 * @exit_c: string to store the error code
 **/
void nfounderr(char *argv, char *exit_c)
{
	perror(argv);
	_strcpy(exit_c, "127");
}
