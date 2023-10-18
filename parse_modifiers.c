#include "main.h"

/**
 * parse_modifiers - handles string modifiers
 * @format: the string format
 * @spec: the format specifier
 *
 * Return: a pointer to the updated format
 */
const char *parse_modifiers(const char *format, format_specifier *spec)
{
	while (*format)
	{
		/* search for conversion modifiers */
		switch (*format)
		{
		case '#':
			if (is_valid_sharp_specifier(*(format + 1)))
				spec->sharp_flag = 1;
			break;
		case '+':
			if (is_valid_plus_specifier(*(format + 1)))
				spec->plus_flag = 1;
			break;
		case ' ':
			if (is_valid_space_specifier(*(format + 1)))
				spec->space_flag = 1;
			break;
		default:
			return (format); /* unknown flag/specifier encountered */
		}
		format++;
	}
	return (format);
}
