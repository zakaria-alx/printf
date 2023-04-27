#include "main.h"

/**
 * etch_unsigned - Prints an unsigned number
 * @args: List a of arguments
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: the number of characters printed.
 */
int etch_unsigned(va_list args, char buffer[],
				  int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = cast_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (output_unsigned_int(0, i, buffer, flags, width, precision, size));
}
