#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: get width
 * @precision: get precision
 * @size: get size
 * Return: the number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
				   int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = cast_size_unsigned_number(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsigned_int(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: get width
 * @precision: get precision
 * @size: get size
 * Return: the number of characters printed
 */
int print_octal(va_list types, char buffer[],
				int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = cast_size_unsigned_number(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned_int(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hex_lower - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: get width
 * @precision: get precision
 * @size: get size
 * Return: the number of characters printed
 */
int print_hex_lower(va_list types, char buffer[],
					int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789abcdef", buffer,
					  flags, 'x', width, precision, size));
}

/**
 * print_hex_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: get width
 * @precision: get precision
 * @size: get size
 * Return: the number of characters printed
 */
int print_hex_upper(va_list types, char buffer[],
					int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789ABCDEF", buffer,
					  flags, 'X', width, precision, size));
}

/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: get precision
 * @size: get size
 * @size: Size specification
 * Return: the number of characters printed
 */
int print_hex(va_list types, char map_to[], char buffer[],
			  int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = cast_size_unsigned_number(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;
	return (write_unsigned_int(0, i, buffer, flags, width, precision, size));
}
