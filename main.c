#include "shs.h"

/**
 * main - detects if the call is interactive or not,
 * then calls a function accordingly.
 * @argc: number of arguments received.
 * @argv: arguments received.
 *
 * Return: 20 if too many arguments, 0 successfully ended.
 */
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (isatty(STDIN_FILENO))
			_itty(*argv);
		else
			_ntty(*argv);
	} else
	{
		return (2);
	}
	return (0);
}
