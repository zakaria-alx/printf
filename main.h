#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define MINUS '-'
#define F_MINUS 1

#define PLUS '+'
#define F_PLUS 2

#define ZERO '0'
#define F_ZERO 4

<<<<<<< HEAD
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
=======
#define HASH '#'
#define F_HASH 8

#define SPACE ' '
#define F_SPACE 16

#define _NULL '\0'
#define F_NULL 0

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/* Struct */
/**
 * _flag - typedef struct flag +, -, #, space, 0
 * @flag: +, -, #, space, 0
 * @repr: 2, 1, 8, 16, \0
 * **/
typedef struct _flag
{
	char flag;
	int repr;
} Flag;
>>>>>>> ab0cb6056dca68d390d77d5074a811e74a00fd84

/**
 * _specifier: struct for conversion modifiers
 * @spec: conversion modifier character
 * @fn: function associated with the character
 * **/
typedef struct _specifier
{
	char spec;
	int (*fn)(va_list, char[], int, int, int, int);

} Specifier;

int _printf(const char *format, ...);
int print(const char *fmt, int *i,
		  va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int etch_char(va_list types, char buffer[],
			  int flags, int width, int precision, int size);
int etch_string(va_list types, char buffer[],
				int flags, int width, int precision, int size);
int etch_percent(va_list types, char buffer[],
				 int flags, int width, int precision, int size);

/* Functions to print numbers */
int etch_integer(va_list types, char buffer[],
				 int flags, int width, int precision, int size);
int etch_binary(va_list types, char buffer[],
				int flags, int width, int precision, int size);
int etch_unsigned(va_list types, char buffer[],
				  int flags, int width, int precision, int size);
int etch_octal(va_list types, char buffer[],
			   int flags, int width, int precision, int size);
int etch_hex_low(va_list types, char buffer[],
				 int flags, int width, int precision, int size);
int etch_hex_upper(va_list types, char buffer[],
				   int flags, int width, int precision, int size);

int output_hex(va_list types, char map_to[],
			   char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int etch_upper_string(va_list types, char buffer[],
					  int flags, int width, int precision, int size);

/* Funcion to print memory address */
int etch_pointer(va_list types, char buffer[],
				 int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int etch_reverse(va_list types, char buffer[],
				 int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int etch_rot13(va_list types, char buffer[],
			   int flags, int width, int precision, int size);

/* width handler */
int output_char(char c, char buffer[],
				int flags, int width, int precision, int size);
int output_number(int is_positive, int ind, char buffer[],
				  int flags, int width, int precision, int size);
int output_buffer_number(int ind, char bff[], int flags, int width, int precision,
						 int length, char padd, char extra_c);
int output_pointer(char buffer[], int ind, int length,
				   int width, int flags, char padd, char extra_c, int padd_start);
int output_unsigned_int(int is_neg, int ind,
						char buffer[],
						int flags, int width, int precision, int size);

int is_char(char);
int hex_correct(char, char[], int);
int is_digit(char);

long int cast_number(long int num, int size);
long int cast_unsigned_int(unsigned long int num, int size);

#endif
