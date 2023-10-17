#include "main.h"

/**
 * handle_string - appends a string to the string buffer
 * @spec: format specifier information (unused)
 * @args: the arguments list
 * @buffer: the string buffer to store the result
 *
 * Return: the number of characters appended to the string @buffer
 */
int handle_string(
	__attribute__((unused)) const format_specifier * spec,
	va_list args, string_buffer *buffer)
{
	char *str;
	int characters_added;
	size_t initial_length;

	str = va_arg(args, char *);
	initial_length = buffer->length;

	if (str)
	{
		append_string(buffer, str);
	}
	else
	{
		append_string(buffer, "(null)");
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_string_reversal - appends a reversed string to the string buffer
 * @spec: format specifier information (unused)
 * @args: the arguments list
 * @buffer: the string buffer to store the result
 *
 * Return: the number of characters appended to the string @buffer
 */
int handle_string_reversal(
	__attribute__((unused)) const format_specifier * spec,
	va_list args, string_buffer *buffer)
{
	char *str, *dup_str;
	int characters_added;
	size_t str_len, initial_length;

	str = va_arg(args, char *);
	initial_length = buffer->length;

	if (str)
	{
		dup_str = _strdup(str);
		if (dup_str == NULL)
			return (0); /* memory allocation failed, nothing is written */

		str_len = _strlen(str);
		_reverse_str(dup_str, str_len);
		append_string(buffer, dup_str);
		safe_free(dup_str);
	}
	else
	{
		append_string(buffer, "(null)");
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_rot13 - appends a ROT13 string to the string buffer
 * @spec: format specifier information (unused)
 * @args: the arguments list
 * @buffer: the string buffer to store the result
 *
 * Return: the number of characters appended to the string @buffer
 */
int handle_rot13(
	__attribute__((unused)) const format_specifier * spec,
	va_list args, string_buffer *buffer)
{
	char *str, *dup_str;
	int characters_added;
	size_t initial_length;

	str = va_arg(args, char *);
	initial_length = buffer->length;

	if (str)
	{
		dup_str = _strdup(str);
		if (dup_str == NULL)
			return (0); /* memory allocation failed, nothing is written */

		rot13(dup_str);
		append_string(buffer, dup_str);
		safe_free(dup_str);
	}
	else
	{
		append_string(buffer, "(null)");
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_custom_string - appends a custom string to the string buffer
 * @spec: format specifier information (unused)
 * @args: the arguments list
 * @buffer: the string buffer to store the result
 *
 * Return: the number of characters appended to the string @buffer
 */
int handle_custom_string(
	__attribute__((unused)) const format_specifier * spec,
	va_list args, string_buffer *buffer)
{
	char *str, *dup_str;
	int characters_added;
	size_t initial_length;

	str = va_arg(args, char *);
	initial_length = buffer->length;

	if (str)
	{
		dup_str = _strdup(str);
		if (dup_str == NULL)
			return (0); /* memory allocation failed, nothing is written */

		/* Actual logic to handle the %S format specifier will be added soon */
		append_string(buffer, dup_str);
		safe_free(dup_str);
	}
	else
	{
		append_string(buffer, "(null)");
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
