#include "shs.h"

/**
 * _itoa - creates a space in memory and stores an integer
 *
 * @n: Pointer to memory address to store integer into
 * Return: returns a pointer to the created string
 */
char *_itoa(int n)
{
	int i, temp;
	char *s;

	temp = n;
	for (i = 0; temp / 10 != 0; i++)
		temp = temp / 10;
	s = malloc((i + 2) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[i + 1] = '\0';
	for (; i >= 0; i--)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

/**
 * trimspaces - Removes spaces at the start of a string
 *
 * @pinput: pointer to address with string to remove spaces from
 */
void trimspaces(char **pinput)
{
	int i = 0;

	while ((*pinput)[0] == ' ' || (*pinput)[0] == '\t')
	{
		(*pinput)++;
		i++;
	}
}
