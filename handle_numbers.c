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
	long int n =
		(spec->length == 'l') ? va_arg(args, long int) : va_arg(args, int);
	char result[21];
	size_t initial_length = buffer->length;
	int characters_added, len;
	format_specifier *tmp_spec = (format_specifier *)spec;

	if (spec->precision)
	{
		tmp_spec->zero_flag = 1; /* handle precision for signed integers */
		tmp_spec->width = (n < 0) ? spec->precision + 1 : spec->precision;
	}
	_itob(n, result, DEC);
	len = _strlen(result);
	if (tmp_spec->plus_flag && n >= 0)
	{
		append_char(buffer, '+'); /* handle the '+' flag */
		tmp_spec->width -= spec->plus_flag;
	}
	else if (tmp_spec->space_flag && n >= 0)
	{
		append_char(buffer, ' '); /* handle the space flag */
		tmp_spec->width -= tmp_spec->space_flag;
	}
	if (tmp_spec->zero_flag && !tmp_spec->minus_flag)
	{
		if (n < 0)
			return (neg_zero_handler(tmp_spec, result, buffer, len));
		handle_width(tmp_spec, buffer, len);
	}
	if (tmp_spec->width && !tmp_spec->minus_flag)
		handle_width(tmp_spec, buffer, len);
	if (!(n < 0 && spec->zero_flag) || !(n == 0 && !spec->precision))
		append_string(buffer, result);

	if (tmp_spec->minus_flag)
		handle_width(tmp_spec, buffer, len); /* handle the '-' flag */

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
	size_t n;
	char result[21];
	size_t initial_length = buffer->length;
	int characters_added, len;
	format_specifier *tmp_spec = (format_specifier *)spec;

	if (spec->length == 'l')
		n = va_arg(args, unsigned long int);
	else
		n = va_arg(args, unsigned int);

	if (spec->precision)
	{
		tmp_spec->zero_flag = 1; /* handle precision for unsigned integers */
		tmp_spec->width = spec->precision;
	}

	utob(n, result, DEC);
	len = _strlen(result);

	if (spec->zero_flag && !spec->minus_flag)
		handle_width(tmp_spec, buffer, len);

	if (spec->width && spec->minus_flag == 0)
		handle_width(tmp_spec, buffer, len);

	if (!(n == 0 && !spec->precision))
		append_string(buffer, result);
	else
		append_string(buffer, result);

	if (spec->minus_flag)
		handle_width(tmp_spec, buffer, len);

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
	size_t n;
	char result[23];
	size_t initial_length = buffer->length;
	int characters_added, len = 0;
	format_specifier *tmp_spec = (format_specifier *)spec;

	if (spec->length == 'l')
		n = va_arg(args, unsigned long int);
	else
		n = va_arg(args, unsigned int);
	if (spec->precision)
	{
		tmp_spec->zero_flag = 1; /* handle precision for unsigned integers */
		tmp_spec->width = spec->precision;
	}

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
	if (!(n == 0 && !spec->precision))
		append_string(buffer, result);
	else
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
