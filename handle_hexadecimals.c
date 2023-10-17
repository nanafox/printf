#include "main.h"

/**
 * handle_hex_lower - convert and append an integer in lower hexadecimal
 * format
 * @spec: format specifier information (unused)
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_hex_lower(__attribute__((unused)) const format_specifier * spec,
		va_list args, string_buffer *buffer)
{
	char hex_str[17];
	int characters_added;
	size_t n = va_arg(args, size_t);
	size_t initial_length = buffer->length;

	utob(n, hex_str, HEX);
	append_string(buffer, hex_str);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_hex_upper - convert and append an integer in uppercase hexadecimal
 * format
 * @spec: format specifier information (unused)
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_hex_upper(__attribute__((unused)) const format_specifier * spec,
		va_list args, string_buffer *buffer)
{
	int i;
	char hex_str[17];
	int characters_added;
	size_t n = va_arg(args, size_t);
	size_t initial_length = buffer->length;

	utob(n, hex_str, HEX);
	for (i = 0; hex_str[i] != '\0'; i++)
	{
		if (hex_str[i] >= 'a' && hex_str[i] <= 'f')
		{
			hex_str[i] = hex_str[i] - 'a' + 'A';
		}
	}
	append_string(buffer, hex_str);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
