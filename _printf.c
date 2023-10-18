#include "main.h"

/**
 * _printf - prints a formatted string to stdout
 * @format: the formatted string
 *
 * Return: the number of characters printed to stdout,
 * else -1 if @format is NULL
 */
int _printf(const char *format, ...)
{
	int characters_printed;
	string_buffer buffer;
	va_list args;

	if (format == NULL)
		return (-1); /* invalid format */

	va_start(args, format);

	/* initialize the string buffer to store the result */
	init_string_buffer(&buffer);

	/* get the result while keeping track of the number of characters printed */
	characters_printed = custom_printf(&buffer, format, args);

	va_end(args);
	return (characters_printed);
}
