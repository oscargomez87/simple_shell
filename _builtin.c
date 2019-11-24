#include "shs.h"

/**
 * print_env - print the actual environment.
 * @env: environment variables.
 *
 * Return: void.
 */

void print_env()
{
	int i = 0;
	while(*(environ + i) != NULL)
	{
		printf("%s\n",*(environ + i));
		i++;
	}
}
