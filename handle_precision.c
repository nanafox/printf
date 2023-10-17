#include "main.h"

/**
 * handle_precision - handles precision for format specifiers
 * @format: the format string
 * @spec: format specifier information
 * @buffer: the string buffer to store the result
 *
 * Return: the number of characters added to the buffer
 */
int handle_precision(const char *format, format_specifier *spec,
		string_buffer *buffer)
{
	int precision = 0;
	int characters_added = 0;
	size_t initial_length = buffer->length;

	format++; /* Skip the '.' character */

	while (*format >= '0' && *format <= '9')
	{
		precision = precision * 10 + (*format - '0');
		format++;
	}

	if (precision > 0)
	{
		spec->precision = precision;

		if (*format != '\0')
			append_char(buffer, *format);

		while (precision > 0)
		{
			format++;
			if (*format != '\0')
				append_char(buffer, *format);
			precision--;
		}
	}
	else if (*format == '*')
	{
		/* Handle precision as an argument (e.g., %.3f) */
		spec->precision = -1;

		append_char(buffer, *format);
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
