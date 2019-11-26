#include "shs.h"

/**
 * _getenv - Finds an enviromental variable.
 *
 * @s: enviromental variable to search.
 * Return: If s is found returns a pointer to the start of the variable
 * otherwise returns NULL.
 */
char *_getenv(char *s)
{
	int i, j;
	char *env;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] == s[j]; j++)
			;
		if (environ[i][j] == '=')
		{
			j++;
			env = malloc(strlen(&(environ[i][j])) + 1);
			strcpy(env, &(environ[i][j]));
			return (env);
		}
	}
	return (NULL);
}

void ecodeinit(char **exit_c)
{
	*exit_c = malloc(4 * sizeof(char));
	(*exit_c)[0] = 0 + '0';
	(*exit_c)[1] = '\0';
}
