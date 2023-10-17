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
	format_specifier *spec;

	if (format == NULL)
		return (-1); /* format string is invalid */

	spec = create_format_specifiers();
	if (spec == NULL)
		return (-1); /* memory allocation failed */

	characters_printed = n_chars = 0;
	/* ensure format is not NULL */
	while (*format != '\0')
	{
		/* check if we are at the beginning of a format mark */
		if (*format == '%')
		{
			format++;
			/* handle precision and width modifiers */
			format = parse_modifiers(format, spec, buffer);

			/* handle format specifiers */
			n_chars = select_format_handler(*format, spec, args, buffer);
			characters_printed += n_chars;
		}
		else
		{
			/* it's a normal character, append it to the string buffer and continue */
			append_char(buffer, *format);
			characters_printed++;
		}

		/* move to the next character in the format string */
		format++;
	}

	/* write the final string to stdout */
	print_str_buffer(buffer->data, characters_printed);

	/* clean up allocated memory */
	safe_free(buffer->data);
	safe_free(spec);

	return (characters_printed);
}
