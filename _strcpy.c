/**
 * _strcpy - copies a string to a pointer
 * @dest: string dest
 * @src: string source
 * Return: pointer to array
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i])
		i++;
	for (j = 0; j < i; j++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (&*(dest - i));
}
