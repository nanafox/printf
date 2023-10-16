#include "main.h"

/**
 * parse_modifiers - handles string modifiers
 * @format: the string format
 * @spec: the format specifier
 * @buffer: the buffer to store the string
 *
 * Return: a pointer to the updated format
 */
const char *parse_modifiers(const char *format, format_specifier *spec,
		string_buffer *buffer)
{
	const char *fmt_marks = "idfFcsSrRuxXop";
	char *tmp_fmt = (char *) format;

	while (*tmp_fmt && !_strchr(fmt_marks, *tmp_fmt))
	{
		/* parse format string for modifiers */
		switch (*tmp_fmt)
		{
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				handle_width(tmp_fmt, spec, buffer);
				break;
			case '.':
				handle_precision(tmp_fmt, spec, buffer);
				break;
			case 'l':
				spec->length = 'l';
				break;
			case 'h':
				spec->length = 'h';
				break;
		}
		tmp_fmt++;
	}
	return (format);
}
