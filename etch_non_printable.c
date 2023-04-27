#include "main.h"

/**
 * etch_upper_string - Prints ascii codes in hexa of non printable chars
 * @args: List of arguments
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: the number of characters printed
 */
int etch_upper_string(va_list args, char buffer[],
					  int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_char(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += hex_correct(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
