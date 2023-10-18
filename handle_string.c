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
		exit(-1); /* exit on NULL string - invalid argument */
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
			return (-1); /* memory allocation failed, nothing is written */

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
			return (-1); /* memory allocation failed, nothing is written */

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
	char hex_str[5];
	char *str, *dup_str;
	int characters_added;
	size_t initial_length, i;

	str = va_arg(args, char *);
	initial_length = buffer->length;

	if (str)
	{
		dup_str = _strdup(str);
		if (dup_str == NULL)
			return (-1); /* memory allocation failed, nothing is written */

		for (i = 0; dup_str[i] != '\0'; i++)
		{
			if (is_non_print(dup_str[i]))
			{
				char_to_hex(hex_str, dup_str[i]);
				append_string(buffer, hex_str);
			}
			else
			{
				append_char(buffer, dup_str[i]);
			}
		}
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
 * char_to_hex - Changes a character to its hex equivalent
 * @buffer: The buffer to store the formatted char
 * @ch: The character in question
 *
 * Return Nothing
 */
void char_to_hex(char *buffer, unsigned char ch)
{
	const char *hex_chars = "0123456789ABCDEF";

	buffer[0] = '\\';
	buffer[1] = 'x';
	buffer[2] = hex_chars[ch >> 4]; /* first hex digit */
	buffer[3] = hex_chars[ch & 0x0F];  /* second hex digit */
}
