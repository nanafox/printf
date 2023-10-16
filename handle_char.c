#include "main.h"

/**
 * handle_char - appends a character to the string buffer
 * @args: arguments list
 * @buffer: string buffer to store the result
 * @spec:  pointer to a format specifier
 *
 * Return: returs the number of characters printed,
 * which is 1 if a character is successfully appended to the string buffer,
 * or 0 if the character appending fails
 */
int handle_char(__attribute__((unused))
		const format_specifier * spec, va_list args, string_buffer *buffer)
{
	char ch = va_arg(args, int);
	size_t initial_length = buffer->length;
	int characters_printed;

	append_char(buffer, ch);

	characters_printed = buffer->length - initial_length;
	return (characters_printed);
}

/**
 * handle_percent - appends the percentage to the string buffer
 * @args: arguments list
 * @buffer: string buffer to store the result
 * @spec:  pointer to a format specifier
 *
 * Return: Returns the number 1, indicating that
 * a single percent character '%' has been appended to the string buffer
 */
int handle_percent(__attribute__((unused)) const format_specifier * spec,
		__attribute__((unused)) va_list args, string_buffer *buffer)
{
	append_char(buffer, '%');

	return (1);
}
