#include "main.h"

/**
 * etch_percent - Prints a percent sign
 * @args: List of arguments to be printed.
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers.
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: the number of characters printed
 */

int etch_percent(va_list args, char buffer[],
				 int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
