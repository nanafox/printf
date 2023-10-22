#include "main.h"
#include <limits.h>

/**
 * _itob - convert integer to the specified base and stores the result
 * as a string
 *
 * @number: the number to convert
 * @buffer: the string buffer to store the result
 * @base: the base to convert @number to
 */
#include "main.h"
#include <limits.h>

void _itob(ssize_t number, char *buffer, int base)
{
	size_t len = 0;
	size_t tmp_num = (number < 0) ? -number : number;
	ssize_t sign = number;
	char digit;

	/* handle long integers */
	if (number == LONG_MIN)
		tmp_num = (size_t)LONG_MAX + 1;

	if (number == SHRT_MIN)
		tmp_num = (size_t)SHRT_MAX + 1;

	if (base != BIN && base != OCT && base != DEC && base != HEX)
		return; /* invalid base */

	if (tmp_num == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		while (tmp_num > 0)
		{
			digit = (char)(tmp_num % base);
			buffer[len++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
			tmp_num /= base;
		}
	}

	/* add the negative sign if necessary */
	if (number < 0 && (base == DEC || base == HEX))
	{
		sign = -number;
		tmp_num = (size_t)sign;
		buffer[len++] = '-';
	}

	buffer[len] = '\0';
	_reverse_str(buffer, len);
}
