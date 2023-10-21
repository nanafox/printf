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
			if (isdigit(*(format + 1)))
			{
				spec->width = _atoi(format + 1);
				format = update_format(format);
			}
			break;
		case '1': case '2': case '3': case '4':	case '5':
		case '6': case '7': case '8': case '9':
			spec->width = _atoi(format);
			format = update_format(format);
			break;
		case '-':
			spec->minus_flag = 1;
			break;
		case '*':
			spec->width = va_arg(args, int);
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
	while (isdigit(*format))
		format++;

	return (format - 1);
}
