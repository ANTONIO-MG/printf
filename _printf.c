#include "main.h"

/**
 * _printf - function that works like the standard printf
 * @format: checks the format on which to execute _printf
 * Return: prints out formatted output to STDIO
 */

int _printf(const char *format, ...)
{
	int letters = 0;
	int position = 0;

	va_list my_args;

	va_start(my_args, format);
	/* checks if format is null*/
	if (format == NULL)
		return ('\0');
	/* assigns position by running position function*/
	position = _position(format);
	/* checks if there is a flag*/
	if (position == -1)
	{
		write(1, format, strlen(format));
		va_end(my_args);
		letters = strlen(format);
	}
	else if (position >= 0)
	{
		if (format[position + 1] == 's')
			letters = _string(format, va_arg(my_args, char *));
		else if (format[position + 1] == 'c')
			letters = _character(format, va_arg(my_args, char *));
		else
			printf("feature still coming\n");
	}

	va_end(my_args);

	return (letters);
}
