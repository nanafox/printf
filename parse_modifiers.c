#include "main.h"

/**
 * parse_modifiers - handles string modifiers
 * @format: the string format
 * @spec: the format specifier
 * @args: arguments list
 * Return: a pointer to the updated format
 */
const char *parse_modifiers(const char *format, format_specifier *spec,
							va_list args)
{
	while (*format)
	{
		/* search for conversion modifiers */
		if (*format == '0' && is_valid_zero_specifier(*(format + 1)))
			spec->zero_flag = 1;
		else if (*format == '0' && is_valid_zero_specifier(*(format + 2)))
		{
			format++;
			spec->zero_flag = 1;
			spec->width = _atoi(format);
		}
		else if (isdigit(*format) && is_valid_width_specifier(*(format + 1)))
			spec->width = _atoi(format);
		else if (*format == '*' && is_valid_width_specifier(*(format + 1)))
			spec->width = va_arg(args, int);
		else if (*format == '#' && is_valid_sharp_specifier(*(format + 1)))
			spec->sharp_flag = 1;
		else if (*format == '+' && is_valid_plus_specifier(*(format + 1)))
			spec->plus_flag = 1;
		else if (*format == ' ' && is_valid_space_specifier(*(format + 1)))
			spec->space_flag = 1;
		else
			return (format); /* unknown flag or specifier encountered */
		format++;
	}
	return (format);
}
