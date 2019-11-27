/**
 * _strcat - Concatenates 2 strings
 * @dest: Concatenated string destination
 * @src: string source
 * Return: pointer to resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (*(dest + i))
	{
		i++;
	}
	for (j = 0; *(src + j); j++, i++)
	{
		*(dest + i) = *(src + j);
	}
	*(dest + i) = '\0';
	return (dest);
}
