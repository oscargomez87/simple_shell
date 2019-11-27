#include "shs.h"

/**
 * _findcmd - finds the command adquired from input,
 * searching PATH in case is not a full path
 *
 * @pinput: User input.
 * @env: string with PATH value
 * Return: -1 if pinput is found but is a directory,
 * 127 if pinput can't be found in PATH, 0 otherwise
 */
int _findcmd(char **pinput, char *env)
{
	char *envcp = NULL;
	struct stat sb;

	if (access(*pinput, F_OK) == 0)
	{
		stat(*pinput, &sb);
		if ((sb.st_mode & S_IFMT) == S_IFDIR)
			return (126);
		else if  ((sb.st_mode & S_IFMT) == S_IFREG)
			return (0);
	}
	if (env != NULL)
	{
		envcp = malloc(_strlen(env) + 1);
		if (envcp == NULL)
			return (-1);
		_strcpy(envcp, env);
		if (_getpath(pinput, envcp) == 0)
		{
			free(envcp);
			return (0);
		}
		free(envcp);
		return (127);
	} else
		return (-1);
}
