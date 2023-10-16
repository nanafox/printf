#include "main.h"

/**
 * print_str_buffer - prints a string to stdout
 * @str: the string to print
 * @len: the length of the string
 */
void print_str_buffer(const char *str, size_t len)
{
	write(1, str, len);
}
