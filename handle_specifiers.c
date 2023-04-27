#include "main.h"

/**
 * handle_specifiers - Prints an argument based on
 * its conversion specifiers
 * @format: is a character string
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: 1024 buffer.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: get precision
 * @size: get size
 * Return: 1 or 2;
 */
int handle_specifiers(const char *format, int *ind,
					  va_list list, char buffer[],
					  int flags, int width, int precision, int size)
{
	int i, len = 0, printed = -1;
	const specifiers *specifiers = get_specifiers();

	for (i = 0; specifiers[i].spec != '\0'; i++)
		if (format[*ind] == specifiers[i].spec)
			return (specifiers[i].fn(list, buffer, flags, width, precision, size));

	if (specifiers[i].spec == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);

		if (format[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &format[*ind], 1);
		return (len);
	}
	return (printed);
}
