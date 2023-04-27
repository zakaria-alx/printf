#include "main.h"

/**
 * etch_hex_low - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: the number of characters printed
 */
int etch_hex_low(va_list args, char buffer[],
				 int flags, int width, int precision, int size)
{
	return (output_hex(args, "0123456789abcdef", buffer,
					   flags, 'x', width, precision, size));
}

/**
 * etch_hex_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: the number of characters printed
 */
int etch_hex_upper(va_list args, char buffer[],
				   int flags, int width, int precision, int size)
{
	return (output_hex(args, "0123456789ABCDEF", buffer,
					   flags, 'X', width, precision, size));
}

/**
 * output_hex - Prints a hexadecimal number in lower or upper
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @flag_ch: Calculates active flags
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * @size: Computed size specification
 * Return: the number of characters printed
 */
int output_hex(va_list args, char map_to[], char buffer[],
			   int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = cast_unsigned_int(num, size);

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
	return (output_unsigned_int(0, i, buffer, flags, width, precision, size));
}
