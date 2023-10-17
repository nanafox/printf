#include "main.h"

/**
 * handle_char - appends a character to the string buffer
 * @args: arguments list
 * @buffer: string buffer to store the result
 * @spec:  pointer to a format specifier
 *
 * Return: 1, the character appended to the string buffer
 */
int handle_char(__attribute__((unused))
		const format_specifier * spec, va_list args, string_buffer *buffer)
{
	char ch = va_arg(args, int);

	append_char(buffer, ch);

	return (1);
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
