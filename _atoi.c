/**
 * _atoi - convert string to integer
 * @s: string to convert
 * Return: integer
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int n = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign = sign * -1;
		} else if (s[i] >= 0 + '0' && s[i] <= 9 + '0')
		{
			n = n * 10 + s[i] - '0';
		} else if (s[i - 1] >= 0 + '0' && s[i - 1] <= 9 + '0')
			break;
		i++;
	}
	return (sign * n);
}
