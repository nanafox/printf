#include "main.h"

/**
 * select_format_handler - selects the appropriate handler for a format
 * specifier
 * @specifier: the specific format specifier to match
 * @spec: a pointer to the format specifier structure containing specifier
 * information
 * @args: the va_list of arguments
 * @buffer: pointer to the string_buffer structure for output
 *
 * Description: This function selects and invokes the appropriate handler
 * function based on the format specifier provided in the @spec parameter.
 * It searches for the matching specifier in the 'format_specifiers' array
 * and uses the associated handler function to process the specifier. If no
 * match is found, it handles the specifier as needed, such as appending it
 * to the @buffer.
 *
 * Return: the function that handles the @specifier, else the number of
 * characters added to the @buffer after the unknown specifier is written.
 */
int select_format_handler(const char specifier, format_specifier *spec,
						  va_list args, string_buffer *buffer)
{
	int i, characters_added;
	size_t initial_length = buffer->length;

	for (i = 0; spec[i].specifier != '\0'; i++)
	{
		/* set the flag if it's available in the format string */
		if (spec[i].specifier == specifier)
		{
			if (spec->plus_flag && is_valid_plus_specifier(specifier))
				spec[i].plus_flag = 1;
			if (spec->space_flag && is_valid_space_specifier(specifier))
				spec[i].space_flag = 1;
			if (spec->sharp_flag && is_valid_sharp_specifier(specifier))
				spec[i].sharp_flag = 1;
			if (spec->zero_flag && is_valid_zero_specifier(specifier))
				spec[i].zero_flag = 1;
			if (spec->width && is_valid_width_specifier(specifier))
				spec[i].width = spec->width;
			if (spec->minus_flag && is_valid_width_specifier(specifier))
				spec[i].minus_flag = 1;
			if (spec->precision && is_valid_width_specifier(specifier))
				spec[i].precision = spec->precision;
			if (spec->length && is_valid_length_specifier(specifier))
				spec[i].length = spec->length;

			/* invoke the appropriate function to handle the found specifier */
			return (spec[i].handler(&spec[i], args, buffer));
		}
	}
	/* the specifier is not found, handle it as needed */
	append_char(buffer, '%');
	append_char(buffer, specifier);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
