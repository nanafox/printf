#include "main.h"

/**
 * create_format_specifiers - creates an array of structs to hold
 * functions for handling format string
 *
 * Description: This function creates an array containing all the format
 * specifiers that should be handled by the custom_printf() function.
 * In the event where an invalid specifier is encountered, NULL is returned.
 * Note that the memory for this array was allocated through malloc() and must
 * be freed using safe_free() when it is no longer needed to avoid memory leaks
 *
 * Return: an array of format specifiers
 */
format_specifier *create_format_specifiers(void)
{
	static format_specifier specifiers[] = {
		{'d', 0, 0, 0, 0, 0, 0, 0, 0, handle_decimal},
		{'i', 0, 0, 0, 0, 0, 0, 0, 0, handle_decimal},
		{'c', 0, 0, 0, 0, 0, 0, 0, 0, handle_char},
		{'%', 0, 0, 0, 0, 0, 0, 0, 0, handle_percent},
		{'s', 0, 0, 0, 0, 0, 0, 0, 0, handle_string},
		{'S', 0, 0, 0, 0, 0, 0, 0, 0, handle_custom_string},
		{'r', 0, 0, 0, 0, 0, 0, 0, 0, handle_string_reversal},
		{'R', 0, 0, 0, 0, 0, 0, 0, 0, handle_rot13},
		{'x', 0, 0, 0, 0, 0, 0, 0, 0, handle_hex_lower},
		{'X', 0, 0, 0, 0, 0, 0, 0, 0, handle_hex_upper},
		{'b', 0, 0, 0, 0, 0, 0, 0, 0, handle_binary},
		{'o', 0, 0, 0, 0, 0, 0, 0, 0, handle_octal},
		{'u', 0, 0, 0, 0, 0, 0, 0, 0, handle_unsigned_int},
		{'p', 0, 0, 0, 0, 0, 0, 0, 0, handle_pointer},
	};

	/* calculate the number of specifiers in the array */
	size_t num_specifiers = sizeof(specifiers) / sizeof(specifiers[0]);

	/* allocate memory for the format_specifiers array and copy the content */
	format_specifier *format_specifiers = malloc(
			num_specifiers * sizeof(format_specifier));

	/* verify memory allocation was successful before continuing */
	if (format_specifiers == NULL)
	{
		return (NULL);
	}

	_memcpy(
			format_specifiers, specifiers, num_specifiers * sizeof(format_specifier));

	return (format_specifiers);
}
