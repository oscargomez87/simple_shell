#include "shs.h"

/**
 * print_env - print the actual environment.
 * @env: environment variables.
 *
 * Return: void.
 */

void print_env(char **env)
{
	int i = 0;
	while(*(env + i) != NULL)
	{
		printf("%s\n",*(env + i));
		i++;
	}
}
