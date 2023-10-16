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
	int i = 0;
	long long sign = number;

	if (number < 0)
		number = -number;/*If number is negative, take its absolute value */

	switch (number)
	{
		/*bases accepted*/
		case BIN:
		case OCT:
		case DEC:
		case HEX:
			/*Convert remainder to the appropriate character representation*/
			do {
				buffer[i++] = (number % base > 9) ? 'a' + (number % base - 10) :
					(number % base + '0');
			} while ((number /= base) > 0);
		if (sign < 0)
		{
			buffer[i++] = '-';
			/*Reverse the string to get the correct representation*/
			_reverse(buffer, i);
			buffer[i] = '\0';
			break;
			default:
			return;
		}
	}
}
