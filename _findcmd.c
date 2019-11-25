#include "shs.h"

/**
 * _findcmd - finds the command adquired from input,
 * searching PATH in case is not a full path
 *
 * @pinput: User input.
 * @argv: Name of program, used in error printing
 * @env: string with PATH value
 * @errorc: error count
 * Return: -1 if pinput is found but is a directory,
 * -2 if pinput can't be found, 0 otherwise
 */
int _findcmd(char **pinput, char *argv, char *env, int *errorc)
{
	char *envcp = NULL;
	struct stat sb;

	if (access(*pinput, F_OK) == 0)
	{
		stat(*pinput, &sb);
		if ((sb.st_mode & S_IFMT) == S_IFDIR)
			return (-1);
		else if  ((sb.st_mode & S_IFMT) == S_IFREG)
			return (0);
	}
	envcp = malloc(strlen(env) + 1);
	if (envcp == NULL)
		return (-1);
	strcpy(envcp, env);
	if (_getpath(pinput, envcp) == 0)
	{
		free(envcp);
		return (0);
	}
	free(envcp);
	(*errorc)++;
	printf("%s: %d: %s: not found\n",
	       argv, *errorc, *pinput);
	return (-2);
}
