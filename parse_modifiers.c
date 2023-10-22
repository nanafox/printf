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
		if (*format == '0')
		{
			spec->zero_flag = 1;
			spec->width = get_width_precision(format + 1, args);
			format = update_format(format);
		}
		else if (*format == '.')
		{
			spec->precision = get_width_precision(format + 1, args);
			format = update_format(format + 1);
		}
		else if (*format >= '1' && *format <= '9')
		{
			spec->width = get_width_precision(format, args);
			format = update_format(format);
		}
		else if (*format == '-')
			spec->minus_flag = 1;
		else if (*format == '*')
			spec->width = get_width_precision(format, args);
		else if (*format == '#')
			spec->sharp_flag = 1;
		else if (*format == '+')
			spec->plus_flag = 1;
		else if (*format == ' ')
			spec->space_flag = 1;
		else if (*format == 'l' || *format == 'h')
			spec->length = *format;
		else
		{
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
