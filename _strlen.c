#include "main.h"

/**
 * _strlen - calculate the length of a string
 * @str: the string
 *
 * Return: the length of string @str
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str++)
	{
		len++;
	}

	return (len);
}
