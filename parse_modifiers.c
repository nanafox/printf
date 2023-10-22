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
	while (*format && !_strchr("%bidcsSrRxXuop", *format))
	{
		/* search for conversion modifiers */
		switch (*format)
		{
		case '0':
			spec->zero_flag = 1;
			spec->width = get_width_precision(format + 1, args);
			format = update_format(format);
			break;
		case '.':
			spec->precision = get_width_precision(format + 1, args);
			format = update_format(format + 1);
			break;
		case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			spec->width = get_width_precision(format, args);
			format = update_format(format);
			break;
		case '-':
			spec->minus_flag = 1;
			break;
		case '*':
			spec->width = get_width_precision(format, args);
			break;
		case '#':
			spec->sharp_flag = 1;
			break;
		case '+':
			spec->plus_flag = 1;
			break;
		case ' ':
			spec->space_flag = 1;
			break;
		default:
			return (format); /* unknown flag or specifier encountered */
		}
		format++;
	}
	return (format);
}

/**
 * update_format - updates the format string after digits are encountered
 * @format: the format string
 *
 * Note: the digits here refer to the ones given for widths and precision
 *
 * Return: the updated format string
*/
const char *update_format(const char *format)
{
	while (isdigit(*format) || *format == '*')
		format++;

	return (format - 1);
}

/**
 * get_width_precision - get width or precision
 * @format: format string
 * @args: arguments list
 *
 * Return: width or precision
*/
int get_width_precision(const char *format, va_list args)
{
	if (isdigit(*(format)))
	{
		return (_atoi(format));
	}
	else if (*format == '*')
		return (va_arg(args, int));
	return (0);
}
