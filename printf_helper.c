#include "main.h"

/**
 * custom_printf - a custom printf helper implementation
 * @buffer: the string buffer
 * @format: the format string
 * @args: the variable argument list
 *
 * Return: the number of characters printed, or -1 on error
 */
int custom_printf(string_buffer *buffer, const char *format, va_list args)
{
	int characters_printed, n_chars;
	format_specifier *spec = create_format_specifiers();

	if (spec == NULL)
		return (-1); /* memory allocation failed */

	characters_printed = n_chars = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if ((!_strchr("%ibducsSrRxXop", *format) && *(format + 1) == '\0')
					|| *format == '\0')
			{
				safe_free(spec);
				return (-1); /* handle lone '%' as format string */
			}
			/* handle conversion modifiers */
			format = parse_modifiers(format, spec, args);
			if (format == NULL)
				return (-1);
			/* handle format specifiers */
			n_chars = select_format_handler(*format, spec, args, buffer);
			characters_printed += n_chars;
		}
		else
		{
			append_char(buffer, *format);
			characters_printed++;
		}
		format++;
	}
	/* write the final string to stdout */
	print_str_buffer(buffer->data, characters_printed);
	/* clean up allocated memory */
	safe_free(buffer->data);
	safe_free(spec);

	return (characters_printed);
}
