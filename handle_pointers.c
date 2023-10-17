#include "main.h"

/**
 * handle_pointer - convert and append a pointer address in hexadecimal format
 * to the string buffer
 * @spec: format specifier information (unused)
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters added to the string buffer
 */
int handle_pointer(__attribute__((unused)) const format_specifier * spec,
		va_list args, string_buffer *buffer)
{
	char hex_str[17];
	int characters_printed;
	size_t initial_length = buffer->length;
	unsigned long int pointer = va_arg(args, unsigned long int);

	/* handle NULL pointers */
	if (!pointer)
	{
		append_string(buffer, "(nil)");
	}
	else
	{
		/* pointer is address valid */
		utob(pointer, hex_str, HEX);
		append_string(buffer, "0x");
		append_string(buffer, hex_str);
	}

	characters_printed = buffer->length - initial_length;
	return (characters_printed);
}
