#include "main.h"

/**
 * _position - function that produces position of the flag.
 * @string: the string to be checked.
 * Return: the position of the flag or -1 if no flag
 */
int _position(const char *string)
{
	int position = -1;
	int count = 0;

	while (string[count])
	{
		if (string[count] == '%')
		{
			position = count;
			break;
		}
		count++;
	}

	if (position == -1)
	{
		return (-1);
	}

	return (position);
}
