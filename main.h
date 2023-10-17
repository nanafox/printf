#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/* base numerals */
#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16

/* check for non-printable characters */
#define is_non_print(c) ((c < 32 || c >= 127) ? 1 : 0)

/**
 * struct string_buffer - structure to hold a dynamically growing string
 * @data: the character array to store the string
 * @capacity: the capacity of the character array
 * @length: the current length of the string
 */
typedef struct string_buffer
{
	char *data;
	size_t capacity;
	size_t length;
} string_buffer;

void init_string_buffer(string_buffer *buffer);
void append_char(string_buffer *buffer, char c);
void append_string(string_buffer *buffer, const char *str);

/**
 * struct format_specifier - structure to hold format specifier information
 * @specifier: format specifier character (e.g., 'd', 's', 'x', etc.)
 * @width: field width
 * @precision: field precision
 * @length: length modifier ('l' for long, 'h' for short, 0 for none)
 * @handler: pointer to the function that handles this format specifier
 * @format: the original format string
 */
typedef struct format_specifier
{
	char specifier;
	int width;
	int precision;
	char length;
	int (*handler)(const struct format_specifier *, va_list,
			struct string_buffer *);
	const char *format;
} format_specifier;

/* format selector */
int select_format_handler(const char specifier, format_specifier *spec,
		va_list args, string_buffer *buffer);

/* a helper function to the _printf() function */
int custom_printf(string_buffer *buffer, const char *format, va_list args);

/* string modifiers parser */
const char *parse_modifiers(const char *format, format_specifier *spec,
		string_buffer *buffer);

/* creates an array of format specifiers and used by the multiple functions */
format_specifier *create_format_specifiers(void);

/* prints the resultant string buffer */
void print_str_buffer(const char *str, size_t len);

/* string handlers */
int handle_precision(const char *format, format_specifier *spec,
		string_buffer *buffer);
int handle_width(const char *format, format_specifier *spec,
		string_buffer *buffer);
int handle_string(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_custom_string(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_rot13(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_string_reversal(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_char(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_percent(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_float(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_unsigned(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_decimal(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_unsigned_int(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_binary(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_hex_lower(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_hex_upper(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_octal(const format_specifier *spec, va_list args,
		string_buffer *buffer);
int handle_pointer(const format_specifier *spec, va_list args,
		string_buffer *buffer);

/* prototype for the _printf function */
int _printf(const char *format, ...);

/* handles number to string conversion */
void _itob(ssize_t number, char *buffer, int base);

/* string manipulation functions */
void _reverse_str(char *buffer, size_t len);
char *_strchr(const char *s, int c);
char *rot13(char *s);
size_t _strlen(const char *str);
char *_strdup(const char *s);
char *utob(size_t number, char *buffer, int base);

/* memory management functions */
void *_realloc(void *old_mem_blk, size_t old_size, size_t new_size);
void *_memcpy(void *dest, const void *src, size_t n);
/* a safer way to deallocate dynamic memory */
void _free(void **ptr);
#define safe_free(p) _free((void **) &(p))

#endif /* MAIN_H */
