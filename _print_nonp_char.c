#include "main.h"

/**
 * print_nonp_char - Prints non printable characters
 * with another representation
 * @str: string to modify
 *
 * Return: Return the formated string
 */
char *print_nonp_char(const char *str)
{
	size_t length = _strlen(str);
	char *mod_string;
	char *formatted_str;

	/* Allocate memory for formatted string */
	mod_string = malloc(alloc_length * 4);

	if (mod_string == NULL)
		return (NULL); /*Return Null if Memory Allocation fails*/

	/* store the starting point of the formatted string */
	formatted_str = mod_string;

	while (*str)
	{
		/*check if character is non printable */
		if (is_non_print(*str))
		{
			/* format and store in the buffer */
			char_to_hex(mod_string, (unsigned char)*str);
			mod_string += 4;
		}
		else
		{
			/* store directly in the buffer if not a non printable */
			*mod_string = *str;
			mod_string++;

		}
		*mod_string = '\0';
	}
	return (mod_string);
}
