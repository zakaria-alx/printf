#include "main.h"

void bufferize(char buffer[], int *cursor);

/**
 * _printf - Custom _printf function
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int i, unk = 0, knw = 0;
	int flags, width, precision, size, cursor = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[cursor++] = format[i];
			if (cursor == BUFF_SIZE)
			{
				bufferize(buffer, &cursor);
			}
			knw++;
		}
		else
		{
			bufferize(buffer, &cursor);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			unk = print(format, &i, args, buffer,
						flags, width, precision, size);
			if (unk == -1)
				return (-1);
			knw += unk;
		}
	}

	bufferize(buffer, &cursor);
	va_end(args);

	return (knw);
}

Specifier *get_specifiers(void)
{
	static Specifier specs[] = {
		{'c', etch_char},
		{'s', etch_string},
		{'%', etch_percent},
		{'i', etch_integer},
		{'d', etch_integer},
		{'b', etch_binary},
		{'u', etch_unsigned},
		{'o', etch_octal},
		{'x', etch_hex_low},
		{'X', etch_hex_upper},
		{'p', etch_pointer},
		{'S', etch_upper_string},
		{'r', etch_reverse},
		{'R', etch_rot13},
		{'\0', NULL}};

	return (specs);
}

/**
 * print - Prints an argument based on its type
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 * @args: List of arguments to be printed.
 * @cursor: cursor.
 * @buffer: local buffer of 1024 chars .
 * @flags: Calculates active flags
 * @width: width for non-custom conversion specifiers.
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: 1 or 2;
 */
int print(const char *format, int *cursor, va_list args, char buffer[],
		  int flags, int width, int precision, int size)
{
	int i, unk = 0, knw = -1;
	const Specifier *specs = get_specifiers();

	for (i = 0; specs[i].spec != '\0'; i++)
		if (format[*cursor] == specs[i].spec)
			return (specs[i].fn(args, buffer, flags, width, precision, size));

	if (specs[i].spec == '\0')
	{
		if (format[*cursor] == '\0')
			return (-1);
		unk += write(1, "%%", 1);

		if (format[*cursor - 1] == ' ')
			unk += write(1, " ", 1);
		else if (width)
		{
			--(*cursor);
			while (format[*cursor] != ' ' && format[*cursor] != '%')
				--(*cursor);
			if (format[*cursor] == ' ')
				--(*cursor);
			return (1);
		}
		unk += write(1, &format[*cursor], 1);
		return (unk);
	}
	return (knw);
}

/**
 * bufferize - Prints the contents of the buffer if it exist
 * @buffer: local buffer of 1024 chars
 * @cursor: Index at which to add next char, represents the length.
 */
void bufferize(char buffer[], int *cursor)
{
	if (*cursor > 0)
	{
		write(1, &buffer[0], *cursor);
	}
	*cursor = 0;
}
