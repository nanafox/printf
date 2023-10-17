#include "main.h"
#include <stdlib.h>

/**
 * _strdup - creates a duplicate of the string str
 * @str: pointer to the string created
 *
 * Return: Returns Null if str is NUll, Returns Null if
 * insufficient memory is available
 */
char *_strdup(const char *str)
{
	int length;
	int i;
	char *strup;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		;

	strup = (char *)malloc(length + 1);
	if (strup == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		*(strup + i) = *(str + i);
	}
	return (strup);
}
