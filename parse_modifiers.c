#include "main.h"
#include <stdio.h>

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
		case '0':
			if (is_valid_zero_specifier(*(format + 1)))
			{
				spec->zero_flag = 1;
				spec->width = 0;
			}
			else if (is_valid_zero_specifier(*(format + 2)))
			{
				format++;
				spec->zero_flag = 1;
				spec->width = _atoi(format);
			}
			break;
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
			return (format); /* unknown flag or specifier encountered */
		}
		format++;
	}
	return (format);
}
