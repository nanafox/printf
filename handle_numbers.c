#include "main.h"

/**
 * handle_decimal - convert and append an integer in decimal format to the
 * string buffer
 * @spec: format specifier information
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_decimal(const format_specifier *spec, va_list args,
				   string_buffer *buffer)
{
	int n = va_arg(args, int);
	char result[21];
	size_t initial_length = buffer->length;
	int characters_added, len;
	format_specifier *tmp_spec = (format_specifier *)spec;

	_itob(n, result, DEC);
	len = _strlen(result);

	if (spec->plus_flag && n >= 0)
	{
		append_char(buffer, '+'); /* handle the '+' flag */
		tmp_spec->width -= spec->plus_flag;
	}
	else if (spec->space_flag && n >= 0)
	{
		append_char(buffer, ' '); /* handle the space flag */
		tmp_spec->width -= spec->space_flag;
	}
	if (spec->zero_flag && !spec->minus_flag)
	{
		if (n < 0)
			return (neg_zero_handler(spec, result, buffer, len));
		handle_width(tmp_spec, buffer, len);
	}

	if (spec->width && !spec->minus_flag)
		handle_width((format_specifier *)spec, buffer, len);

	append_string(buffer, result);

	if (spec->minus_flag)
		handle_width((format_specifier *)spec, buffer, len);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_unsigned_int - convert and append an integer in decimal format to the
 * string buffer
 * @spec: format specifier information
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_unsigned_int(const format_specifier *spec, va_list args,
						string_buffer *buffer)
{
	unsigned int n = va_arg(args, unsigned int);
	char result[21];
	size_t initial_length = buffer->length;
	int characters_added, len;

	utob(n, result, DEC);
	len = _strlen(result);

	if (spec->zero_flag && !spec->minus_flag)
	{
		format_specifier *tmp_spec = (format_specifier *)spec;

		handle_width(tmp_spec, buffer, len);
	}
	else if (spec->width && spec->minus_flag == 0)
	{
		handle_width((format_specifier *)spec, buffer, len);
	}
	append_string(buffer, result);
	if (spec->minus_flag)
	{
		handle_width((format_specifier *)spec, buffer, len);
	}

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
int handle_binary(__attribute__((unused)) const format_specifier *spec,
				  va_list args, string_buffer *buffer)
{
	char result[65];
	int characters_added;
	unsigned int n = va_arg(args, unsigned int);
	size_t initial_length = buffer->length;

	utob(n, result, BIN);
	append_string(buffer, result);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_octal - convert and append an integer in octal format to the string
 * buffer
 * @spec: format specifier information
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_octal(const format_specifier *spec, va_list args,
				 string_buffer *buffer)
{
	unsigned int n = va_arg(args, unsigned int);
	char result[23];
	size_t initial_length = buffer->length;
	int characters_added, len = 0;
	format_specifier *tmp_spec = (format_specifier *)spec;

	utob(n, result, OCT);
	len = _strlen(result);

	if (spec->width && spec->minus_flag == 0)
	{
		tmp_spec->width -= spec->sharp_flag;
		handle_width(tmp_spec, buffer, len);
	}

	if (spec->sharp_flag && n > 0)
	{
		tmp_spec->width -= spec->sharp_flag;
		append_char(buffer, '0');
	}

	if (spec->zero_flag && !spec->minus_flag)
		handle_width(tmp_spec, buffer, len);

	append_string(buffer, result);

	if (spec->minus_flag)
		handle_width(tmp_spec, buffer, len);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * neg_zero_handler - handles the appending of negative numbers
 * when the zero flag is used.
 * @spec: format specifier information
 * @result: the string version of the integer number
 * @buffer: string buffer to store the result
 * @len: the length of the string @result
 *
 * Return: the current length of the string buffer
 */
int neg_zero_handler(const format_specifier *spec, char *result,
					 string_buffer *buffer, int len)
{
	char *dup_str;
	format_specifier *tmp_spec = (format_specifier *)spec;

	dup_str = _strdup(result);
	if (dup_str == NULL)
	{
		return (0); /* memory allocation failed */
	}
	_reverse_str(dup_str, len);
	append_char(buffer, '-'); /* append the negative sign */

	/* get the absolute of the number */
	dup_str[len - 1] = '\0';

	/* pad with the necessary amount of zeros */
	handle_width(tmp_spec, buffer, len);
	_reverse_str(dup_str, len - 1);

	/* append the updated the number */
	append_string(buffer, dup_str);
	/* deallocate memory*/
	safe_free(dup_str);

	return (buffer->length);
}
