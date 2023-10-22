#include "main.h"
#include <stdio.h>

static void get_hex_upper(char *hex_str);

/**
 * handle_hex_lower - convert and append an integer in lower hexadecimal
 * format
 * @spec: format specifier information (unused)
 * @args: arguments list
 * @buffer: string buffer to store the result
 *
 * Return: the number of characters appended to the string buffer
 */
int handle_hex_lower(const format_specifier *spec, va_list args,
					 string_buffer *buffer)
{
	char hex_str[17];
	size_t n;
	int characters_added, len;
	size_t initial_length = buffer->length;
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

	utob(n, hex_str, HEX);
	len = _strlen(hex_str);

	if (spec->sharp_flag && n > 0)
	{
		tmp_spec->width -= 2; /* account for the extra characters */
		append_string(buffer, "0x");
	}
	if (spec->zero_flag)
		handle_width(tmp_spec, buffer, len);

	if (spec->width && spec->minus_flag == 0)
		handle_width(tmp_spec, buffer, len);

	if (!(n == 0 && !spec->precision))
		append_string(buffer, hex_str); /* handle precision edge cases first*/
	else
		append_string(buffer, hex_str); /* append hex digits */
	if (spec->minus_flag)
		handle_width(tmp_spec, buffer, len);

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
int handle_hex_upper(const format_specifier *spec, va_list args,
					 string_buffer *buffer)
{
	int len;
	size_t n;
	char hex_str[17];
	int characters_added;
	size_t initial_length = buffer->length;
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

	utob(n, hex_str, HEX);
	len = _strlen(hex_str);
	get_hex_upper(hex_str); /* get the uppercase version of hex digit */

	if (spec->sharp_flag && n > 0)
	{
		tmp_spec->width -= 2;
		append_string(buffer, "0X");
	}
	if (spec->zero_flag)
		handle_width(tmp_spec, buffer, len);

	if (spec->width && spec->minus_flag == 0)
		handle_width(tmp_spec, buffer, len);
	if (!(n == 0 && !spec->precision))
		append_string(buffer, hex_str);
	else
		append_string(buffer, hex_str); /* append hex digits */
	if (spec->minus_flag)
		handle_width(tmp_spec, buffer, len);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * get_hex_upper - updates a hex digit to its uppercase version
 * @hex_str: the hex string to convert
 */
void get_hex_upper(char *hex_str)
{
	int i;

	for (i = 0; hex_str[i] != '\0'; i++)
	{
		if (hex_str[i] >= 'a' && hex_str[i] <= 'f')
		{
			hex_str[i] = hex_str[i] - 'a' + 'A';
		}
	}
}
