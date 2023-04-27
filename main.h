#ifndef MAIN_H
#define MAIN_H

/* Dependencies */
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @spec: The specifier.
 * @fn: The function associated with conversion specifier.
 */
typedef struct _specifiers
{
	char spec;
	int (*fn)(va_list, char[], int, int, int, int);
} specifiers;

specifiers *get_specifiers(void);
int _printf(const char *format, ...);
int handle_specifiers(const char *, int *i, va_list, char[], int, int, int, int);

/* Funtions to print chars and strings */
int print_char(va_list, char[], int, int, int, int);
int print_string(va_list, char[], int, int, int, int);
int print_percent(va_list, char[], int, int, int, int);

/* Functions to print numbers */
int print_int(va_list, char[], int, int, int, int);
int print_binary(va_list, char[], int, int, int, int);
int print_unsigned(va_list, char[], int, int, int, int);
int print_octal(va_list, char[], int, int, int, int);
int print_hex_lower(va_list, char[], int, int, int, int);
int print_hex_upper(va_list, char[], int, int, int, int);

int print_hex(va_list, char map_to[], char[], int, char flag_ch, int, int, int);

/* Function to print non printable characters */
int print_non_printable(va_list, char[], int, int, int, int);

/* Funcion to print memory address */
int print_pointer(va_list, char[], int, int, int, int);

/* Funciotns to handle other specifiers */
int get_flags(const char *, int *i);
int get_width(const char *, int *i, va_list);
int get_precision(const char *, int *i, va_list);
int get_size(const char *, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list, char[], int, int, int, int);

/*Function to print a string in rot 13*/
int print_rot13(va_list, char[], int, int, int, int);

/* width handler */
int handle_spec_char(char c, char[],
					 int, int, int, int);
int write_number(int is_positive, int ind, char[], int, int, int, int);
int write_num(int ind, char bff[], int, int, int, int length, char padd, char extra_c);
int write_pointer(char[], int ind, int length, int, int, char padd, char extra_c, int padd_start);
int write_unsigned_int(int is_negative, int ind, char[], int, int, int, int);

int is_char(char);
int map_hex_code(char, char[], int);
int is_digit(char);

long int cast_size_number(long int num, int);
long int cast_size_unsigned_number(unsigned long int num, int);

#endif
