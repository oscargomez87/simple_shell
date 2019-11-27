/**
 * _strcmp - compare strings
 * @s1: main string to compare
 * @s2: string to compare with s1
 * Return: 1 if s1 is greater than s2, -1 if s1 is less than s1 and 0 if s1
 * matches s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, n;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
			n = 0;
		else
		{
			n = s1[i] - s2[i];
			break;
		}
	}
	return (n);
}
