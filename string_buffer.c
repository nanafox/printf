#include "main.h"

/**
 * init_string_buffer - initializes the string buffer used to store the output
 * @buffer: where to store the result. (Dynamically handled)
 */
void init_string_buffer(string_buffer *buffer)
{
	buffer->data = NULL;
	buffer->capacity = 0;
	buffer->length = 0;
}

/**
 * append_char - appends a character to the string buffer while allocating
 * memory dynamically
 * @buffer: the string buffer to save the result
 * @c: the character to write
 */
void append_char(string_buffer *buffer, char c)
{
	size_t old_capacity = buffer->capacity;
	char *new_data;

	/* handle memory allocation */
	if (buffer->length + 1 >= buffer->capacity)
	{
		buffer->capacity = (old_capacity == 0) ? 2 : old_capacity * 2;
		new_data = _realloc(buffer->data, old_capacity, buffer->capacity);

		if (new_data == NULL)
			return; /* memory allocation failed */

		buffer->data = new_data;
	}
	buffer->data[buffer->length] = c;
	buffer->length++;
	buffer->data[buffer->length] = '\0';
}

/**
 * append_string - appends a string to the string buffer
 * @buffer: the string buffer to hold the result
 * @str: the string to append
 */
void append_string(string_buffer *buffer, const char *str)
{
	while (*str)
	{
		append_char(buffer, *str);
		str++;
	}
}
