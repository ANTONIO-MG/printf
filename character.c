#include "main.h"

/**
 * _character - function that produces entire string output according to format
 * @format: the format to be followed by printf
 * Return: the number of characters printed
 */

int _character(const char *format, ...)
{

	int count, total, x, y, p, replace_count;
	char *ptr;
	va_list my_args;

	count = total = x = y = p = replace_count = 0;

	va_start(my_args, format);

	total = (strlen(format) - 1);
	/* allocate sufficient memory for the final string*/
	ptr = malloc(sizeof(format) * total);

	/* find the position of the percentile*/
	while (format[count])
	{
		if (format[count] == '%')
			p = count;
		count++;
	}

	count = 0;
	y = p + 2;
	replace_count = p + 1;
	/* include part one of string*/
	while (count < p)
	{
		ptr[count] = format[count];
		count++;
	}
	/*replace % part of string*/
	if (count == p)
	{
		ptr[count] = va_arg(my_args, int);
		count++;
	}
	/* add the last part of the string*/
	while (count < total)
	{
		ptr[count] = format[y];
		count++, y++;
	}
	/* print out the entire new string*/
	write(1, ptr, total);

	printf("\n");

	va_end(my_args);
	/* free all teh space you used*/
	free(ptr);

	return (total);
}
