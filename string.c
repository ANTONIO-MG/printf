#include "main.h"

/**
 * _string - produces entire string output according to format
 * @format: the format printf is to follow
 * Return: the number of characters printed
 */

int _string(const char *format, ...)
{

	int count, total, x, y, p, replace_count;
	char *ptr, *string;
	va_list my_args;

	count = total = x = y = p = replace_count = 0;

	va_start(my_args, format);

	string = va_arg(my_args, char *);

	total = (strlen(format) + strlen(string) - 2);
	/* allocate sufficient memory for the final string*/
	ptr = malloc(sizeof(format) * total);

	p = _position(format);
	count = 0;
	y = p + 2;
	replace_count = p + strlen(string);
	/* include part one of string*/
	while (count < p)
	{
		ptr[count] = format[count];
		count++;
	}
	/*replace % part of string*/
	while (count < replace_count)
	{
		ptr[count] = string[x];
		count++, x++;
	}

	while (count < total)
	{
		ptr[count] = format[y];
		count++, y++;
	}
	write(1, ptr, total);

	printf("\n");

	va_end(my_args);
	free(ptr);
	free(string);

	return (total);
}
