#include "main.h"

/**
 * print_char - Prints a char
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: Width
 * @precision: get precision
 * @size: get size
 * Return: the number of characters printed
 */
int print_char(va_list types, char buffer[],
			   int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_spec_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: get width.
 * @precision: get precision
 * @size: get size
 * Return: the number of characters printed
 */

int print_string(va_list types, char buffer[],
				 int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	// Count the length of the string using the strlen() function
	length = strlen(str);

	// If precision is specified, limit the string length to precision
	if (precision >= 0 && precision < length)
		length = precision;

	// Write the string to stdout in chunks of MAX_CHUNK_SIZE
	int bytes_written = 0;
	const int MAX_CHUNK_SIZE = 1024; // Change this to suit your needs
	while (bytes_written < length)
	{
		// Calculate the number of bytes to write in this iteration
		int chunk_size = (length - bytes_written < MAX_CHUNK_SIZE) ? length - bytes_written : MAX_CHUNK_SIZE;

		// Write the chunk to stdout
		if (write(1, &str[bytes_written], chunk_size) < 0)
			return -1;

		bytes_written += chunk_size;
	}

	// Pad the output with spaces if necessary
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
	}

	return bytes_written;
}

/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: get width.
 * @precision: get precision
 * @size: get size
 * Return: the number of characters printed
 */

int print_percent(va_list types, char buffer[],
				  int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: get width.
 * @precision: get precision
 * @size: get size
 * Return: the number of characters printed
 */
int print_int(va_list types, char buffer[],
			  int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = cast_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: List of arguments
 * @buffer: 1024 buffer
 * @flags:  get flags
 * @width: get width.
 * @precision: get precision
 * @size: get size
 *  Return: the number of characters printed
 */
int print_binary(va_list types, char buffer[],
				 int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);

	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
