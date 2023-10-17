#include "main.h"

/**
 * _strdup - Duplicates a string.
 * @str: string to duplicate
 *
 * Description: The _strdup() function returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string @str. Memory for the
 * new string is obtained with malloc() and can be freed with free()
 *
 * Return: A pointer to the duplicated string, NULL if it fails/
 */
char *_strdup(const char *str)
{
	char *dup_str;
	int i = 0;

	if (str == NULL)
		return (NULL); /* handle invalid string */

	dup_str = malloc(_strlen(str) + 1);

	if (dup_str == NULL)
		return (NULL);

	/* duplicate string - a copy process */
	while (str[i] != '\0')
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';

	return (dup_str);
}
