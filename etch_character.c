#include "main.h"

/**
 * output_char - Function that prints a character.
 * @c: char to print.
 * @buffer: local buffer of 1024 chars
 * @flags: flag characters for non-custom conversion specifiers.
 * @width: width for non-custom conversion specifiers.
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size
 *
 * Return: the number of characters printed.
 */
int output_char(char c, char buffer[],
				int flags, int width, int precision, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = pad;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * etch_char - Prints a char
 * @args: List a of arguments
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size
 * Return: the number of characters printed
 */
int etch_char(va_list args, char buffer[],
			  int flags, int width, int precision, int size)
{
	return (output_char(va_arg(args, int), buffer,
						flags, width, precision, size));
}
