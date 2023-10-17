#include "main.h"

/**
 * handle_width - handle the width specifier
 * @format: the format string being processed.
 * @spec: the format specifier to process.
 * @buffer: the string buffer for output.
 *
 * Return: the number of characters added to the buffer
 */
int handle_width(const char *format, format_specifier *spec,
		string_buffer *buffer)
{
	int width = 0;
	int characters_added = 0;
	size_t initial_length = buffer->length;

	format++;

	if (*format >= '0' && *format <= '9')
	{
		while (*format >= '0' && *format <= '9')
		{
			width = width * 10 + (*format - '0');
			format++;
		}

		spec->width = width;

		/* Append width to the output buffer */
		while (width > 0)
		{
			append_char(buffer, ' ');
			width--;
		}
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
