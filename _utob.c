#include "main.h"

/**
 * utob - convert positive integer to the specified base and stores
 * the result as a string
 *
 * @number: the number to convert
 * @buffer: the string buffer to store the result
 * @base: the base to convert @number to
 */
void utob(size_t number, char *buffer, int base)
{
	size_t len = 0;

	switch (base) /* Check base number */
	{
		/* Accepted bases */
		case BIN:
		case OCT:
		case DEC:
		case HEX:
			do {
				buffer[len++] = (number % base > 9) ? ('a' + (number  % base - 10)) :
					(number % base + '0');
			} while ((number /= base) > 0);

			buffer[len] = '\0';
			_reverse_str(buffer, len); /* Get the correct representation */
			break;
		default:
			break;
	}
}
