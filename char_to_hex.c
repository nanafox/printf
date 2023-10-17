#include "main.h"

/**
 * char_to_hex - Changes a character to its hex equivanlent
 * @buffer: The buffer to store the formatted char
 * @ch: The character in question
 *
 * Return Nothing
 */
void char_to_hex(char *buffer, unsigned char ch)
{
	const char *hex_chars = "0123456789ABCDEF";

	buffer[0] = '\\';
	buffer[1] = 'x';
	buffer[2] = hex_chars[ch >> 4]; /* first hex digit */
	buffer[3] = hex_chars[ch & 0x0F];  /* second hex digit */
}
