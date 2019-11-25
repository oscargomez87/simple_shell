#include "shs.h"

/**
 * print_env - print the actual environment.
 *
 * Return: void.
 */

void print_env(void)
{
	int i = 0;

	while (*(environ + i) != NULL)
	{
		printf("%s\n", *(environ + i));
		i++;
	}
}
