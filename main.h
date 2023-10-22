#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/* base numerals */
#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16

/* check for non-printable characters */
#define is_non_print(c) ((c) < 32 || (c) >= 127)

/* macros for flags */
#define is_valid_plus_specifier(c) ((c) == 'i' || (c) == 'd')
#define is_valid_space_specifier(c) (is_valid_plus_specifier(c))
#define is_valid_sharp_specifier(c) ((c) == 'x' || (c) == 'X' || (c) == 'o')
#define is_valid_zero_specifier(c) \
	(is_valid_plus_specifier(c) || is_valid_sharp_specifier(c) || (c) == 'u')
#define is_valid_width_specifier(c) \
	(is_valid_zero_specifier(c) || (c) == 's' || (c) == 'c')
#define is_valid_length_specifier(c) (is_valid_zero_specifier(c))

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
 * @plus_flag: the '+' (plus) flag
 * @space_flag: the ' ' (space) flag
 * @sharp_flag: the '#' flag
 * @zero_flag: the '0' flag
 * @minus_flag: the '-' flag
 * @handler: pointer to the function that handles this format specifier
 */
typedef struct format_specifier
{
	char specifier;
	int width;
	int precision;
	char length;
	int plus_flag;
	int space_flag;
	int sharp_flag;
	int zero_flag;
	int minus_flag;
	int (*handler)(const struct format_specifier *, va_list,
				   struct string_buffer *);
} format_specifier;

/* format selector */
int select_format_handler(const char specifier, format_specifier *spec,
						  va_list args, string_buffer *buffer);

/* a helper function to the _printf() function */
int custom_printf(string_buffer *buffer, const char *format, va_list args);

/* string modifiers parser */
const char *parse_modifiers(const char *format, format_specifier *spec,
							va_list args);

/* creates an array of format specifiers and used by the multiple functions */
format_specifier *create_format_specifiers(void);

/* prints the resultant string buffer */
void print_str_buffer(const char *str, size_t len);

/* string handlers */
int handle_width(format_specifier *spec, string_buffer *buffer, int len);
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
int neg_zero_handler(const format_specifier *spec, char *result,
					 string_buffer *buffer, int len);

/* prototype for the _printf function */
int _printf(const char *format, ...);

/* handles number to string conversion */
void _itob(ssize_t number, char *buffer, int base);
void utob(size_t number, char *buffer, int base);
#define _itoa(c) ((c) + '0')

/* handle string to number conversion*/
int _atoi(const char *nptr);
#define isdigit(c) ((c) >= '0' && (c) <= '9')

/* string manipulation functions */
void _reverse_str(char *buffer, size_t len);
char *_strchr(const char *s, int c);
char *rot13(char *s);
size_t _strlen(const char *str);
char *_strdup(const char *s);
void char_to_hex(char *buffer, unsigned char ch);
const char *update_format(const char *format);
int get_width_precision(const char *format, va_list args);

/* memory management functions */
void *_realloc(void *old_mem_blk, size_t old_size, size_t new_size);
void *_memcpy(void *dest, const void *src, size_t n);
/* a safer way to deallocate dynamic memory */
void _free(void **ptr);
#define safe_free(p) _free((void **)&(p))

#endif /* MAIN_H */
