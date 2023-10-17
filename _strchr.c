#include "main.h"

/**
 * _strchr - locate character in string
 * @s: string
 * @c: character to search
 *
 * Description: The _strchr() function returns a pointer to the first
 * occurrence of the character @c in the string @s.
 *
 * Return: A pointer to the matched character or NULL if the character
 * is not found.
 */
char *_strchr(const char *s, int c)
{
	char *tmp_str = (char *) s;

	/* handle empty string */
	if (tmp_str == NULL)
		return (NULL);

	while (*tmp_str != '\0')
	{
		if (*tmp_str == c)
			return (tmp_str); /* match found */
		tmp_str++;
	}
	/* return a pointer to the null byte if 'c' is a null byte. */
	if (c == '\0')
		return (tmp_str);

	return (NULL); /* no match found or end of string - return NULL */
}
