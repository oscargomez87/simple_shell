/**
 * _itoa - Stores an integer in a pointer to
 * already allocated memory
 *
 * @wait_status: Integet to store in memory address
 * @s: Pointer to memory address to store integer into
 */
void _itoa(int wait_status, char *s)
{
	int i, status;

	status = wait_status;
	for (i = 0; status / 10 != 0; i++)
		status = status / 10;
	s[i + 1] = '\0';
	for (; i >= 0; i--)
	{
		s[i] = (wait_status % 10) + '0';
		wait_status = wait_status / 10;
	}
}
