#include "shs.h"

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


/**
 * trimcomments - Removes all character after a #.
 *
 * @pinput: double pointer to arguments.
 */

void trimcomments(char **pinput)
{
	int i;

	for (i = 0; *(*pinput + i) != '\0'; i++)
		if (*(*pinput + i) == ' ' && *(*pinput + i + 1) == '#')
		{
			for (i += 1; *(*pinput + i) != '\0'; i++)
				*(*pinput + i) = '\0';
			break;
		}
}

void trimexit(char **pinput, char **env, char *exit_c)
{
	char *command_exit = "exit", *temp;
	int i = 0, j = 0, exit_flag = 0, size_of_exit_code = 0, exit_code = 0;

	temp = malloc(5 * sizeof(char));
	if (temp == NULL)
		return;
	for (i = 0; *(*pinput + i) != '\0' && i < 4; i++)
		*(temp + i) = *(*pinput + i);
	*(temp + 4) = '\0';
	if (_strcmp(command_exit, temp) == 0)
		exit_flag = 1;
	else
		return;
	free(temp);
	for (i = 0; *(*pinput + i) != ' '; i++)
		;
	for (j = i + 1; *(*pinput + j) != ' ' && *(*pinput + j) != '\0'; j++)
		size_of_exit_code++;
	temp = malloc((size_of_exit_code + 1) * sizeof(char));
	if (temp == NULL)
		return;
	for (i += 1, j = 0; j < size_of_exit_code; i++, j++)
		*(temp + j) = *(*pinput + i);
	*(temp + j) = '\0';
	exit_code = _atoi(temp);
	free(temp);
	if (exit_flag && exit_code)
	{
		free(exit_c);
		free(*env);
		free(*pinput);
		exit(exit_code);
	}
}







