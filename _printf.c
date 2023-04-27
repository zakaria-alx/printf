#include "main.h"

void clear_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function.
 * @format:  is a character string.
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	static char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			/* _putchar(format[i]); */
			printed_chars++;
			/* _putchar(-1); */
		}
		else
		{
			clear_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_specifiers(format, &i, list, buffer,
										flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	clear_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * clear_buffer - Prints the contents of the buffer if it exist
 * @buffer: 1024 buffer
 * @buff_ind: Index at which to add next char, represents the length.
 */
void clear_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
