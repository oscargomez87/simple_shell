/**
 * _strlen - Returns the length of a string
 * @s: string
 * Return: Length of string
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen(s + 1));
}
