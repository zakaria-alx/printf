#include "main.h"

/**
 * is_char - Checks if c is a valid character
 * @c: Value to check.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_char(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hex_correct - Append ascii in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Appending index.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int hex_correct(char ascii_code, char buffer[], int i)
{
	char chars[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = chars[ascii_code / 16];
	buffer[i] = chars[ascii_code % 16];
	return (3);
}

/**
 * is_digit - Check if character is a digit
 * @c: value to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * cast_number - Casts number to the proper data type
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value
 */
long int cast_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * cast_unsigned_int - Casts a number to the proper data type
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value
 */
long int cast_unsigned_int(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
