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
	extern char **environ;

	while (*environ != NULL)
	{
		while (*(*environ) == *s)
		{
			(*environ)++;
			s++;
		}
		if (*(*environ) == '=')
			return (++(*environ));
		environ++;
	}
	return (NULL);
}
