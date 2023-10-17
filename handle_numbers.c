#include "main.h"

/**
 * handle_decimal - convert and append an integer in decimal format to the
 * string buffer
 * @spec: format specifier information (unused)
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_decimal(__attribute__((unused)) const format_specifier * spec,
		va_list args, string_buffer *buffer)
{
	int n = va_arg(args, int);
	char result[21];
	size_t initial_length = buffer->length;
	int characters_added;

	_itob(n, result, DEC);
	append_string(buffer, result);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_unsigned_int - convert and append an integer in decimal format to the
 * string buffer
 * @spec: format specifier information (unused)
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_unsigned_int(__attribute__((unused)) const format_specifier * spec,
		va_list args, string_buffer *buffer)
{
	size_t n = va_arg(args, size_t);
	char result[21];
	size_t initial_length = buffer->length;
	int characters_added;

	_utob(n, result, DEC);
	append_string(buffer, result);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_binary - convert and append an integer in binary format to the string
 * buffer
 * @spec: format specifier information (unused)
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_binary(__attribute__((unused)) const format_specifier * spec,
		va_list args, string_buffer *buffer)
{
	char result[65];
	int characters_added;
	size_t n = va_arg(args, size_t);
	size_t initial_length = buffer->length;

	_utob(n, result, BIN);
	append_string(buffer, result);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_octal - convert and append an integer in octal format to the string
 * buffer
 * @spec: format specifier information (unused)
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_octal(__attribute__((unused)) const format_specifier * spec,
		va_list args, string_buffer *buffer)
{
	size_t n = va_arg(args, size_t);
	char result[23];
	size_t initial_length = buffer->length;
	int characters_added;

	_utob(n, result, OCT);
	append_string(buffer, result);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
