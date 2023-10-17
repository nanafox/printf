#include "main.h"

/**
 * _strlen - Counts the length of a string
 * @s: the operand used
 *
 * Return: The length of the string
 */
size_t _strlen(const char *s)
{
	size_t count;

	count = 0;

	for (; s; count++)
		s++; /* move to the next character */
	return (count);
}
