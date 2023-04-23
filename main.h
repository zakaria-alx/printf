#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/* printf.c */
int _printf(const char *, ...);

/* handler.c */
int handler(const char *, va_list);
int handle_format(const char *, va_list, int *);

/* format */
int etch_string(va_list);
int etch_char(va_list);
int etch_integer(va_list);
int etch_unsigned(va_list);
int etch_binary(va_list);
int etch_hexadecimal(va_list);
int etch_Hexadecimal(va_list);
int etch_octal(va_list);
int etch_rot(va_list);
int etch_pointer(va_list);
int etch_reverse(va_list);
int etch_String(va_list argList);

/* utilities */

int _strlen(const char *formatPtr);
int etch(char *charPtr);
char *convert_ascii(long int, int);

/* putchar */
int _putchar(char);
int buffer(char);

/**
 * struct _format - struct representing the cases asked in alx
 *
 * @type: indicating which type of @f to call
 * @f: function linked to type
 **/
typedef struct _format
{
	char type;
	int (*f)(va_list);
} format;

#endif
