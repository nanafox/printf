#include "main.h"

/**
 * _itob - convert integer to the specified base and stores the result
 * as a string
 *
 * @number: the number to convert
 * @buffer: the string buffer to store the result
 * @base: the base to convert @number to
 */
void _itob(ssize_t number, char *buffer, int base)
{
	size_t len = 0;
	ssize_t sign = number;

	if (number < 0)
		number = -number; /* get the absolute value of n */

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

			if (sign < 0)
				buffer[len++] = '-';

			buffer[len] = '\0';
			_reverse_str(buffer, len); /* Get the correct representation */
			break;
		default:
			return;
	}
}
