#include "main.h"

/**
 * handle_width - handle the width specifier
 * @spec: the format specifier to process.
 * @buffer: the string buffer for output.
 * @len: length of string
 *
 * Return: the number of characters added to the buffer
 */
int handle_width(format_specifier *spec, string_buffer *buffer, int len)
{
	int characters_added = 0;
	size_t initial_length = buffer->length;

	/* Append width to the output buffer */
	while (spec->width > len)
	{
		if (spec->zero_flag && !spec->minus_flag)
		{
			append_char(buffer, _itoa(0));
			spec->width--;
		}
		else
		{
			append_char(buffer, ' ');
			spec->width--;
		}
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
