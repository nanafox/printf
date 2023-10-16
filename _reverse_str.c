#include "main.h"

/**
 * _reverse_str - reverse string in place
 *
 * @buffer: string to reverse
 * @len: length of the string
 */
void _reverse_str(char *buffer, size_t len)
{
	size_t i, mid;
	char c;

	if (!buffer)
		return; /* invalid string, nothing to do here */
	mid = len / 2;

	for (int i = 0; i <= mid; i++)
	{
		c = buffer[i];

		/* swap values */
		buffer[i] = buffer[len - 1];
		buffer[len - i] = c;
	}
}
