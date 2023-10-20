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
		if (spec[i].specifier == specifier)
		{
			/* set the flag if it's available in the format string */
			if (spec->plus_flag)
				spec[i].plus_flag = 1;
			else if (spec->space_flag)
				spec[i].space_flag = 1;
			else if (spec->sharp_flag)
				spec[i].sharp_flag = 1;
			else if (spec->zero_flag)
			{
				spec[i].zero_flag = 1;
				spec[i].width = spec->width;
			}

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
