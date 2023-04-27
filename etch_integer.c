#include "main.h"

/**
 * output_buffer_number - Write a number using a bufffer
 * @idx: Index of the number in the buffer
 * @buff: local buffer of 1024 chars
 * @flags: flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @prec: precision for non-custom conversion specifiers.
 * @len: Number length
 * @pad: Padding space
 * @flag: Selected flag
 *
 * Return: the number of characters printed
 */
int output_buffer_number(int idx, char buff[],
						 int flags, int width, int prec,
						 int len, char pad, char flag)
{
	int i, p = 1;

	if (prec == 0 && idx == BUFF_SIZE - 2 && buff[idx] == '0' && width == 0)
		return (0);
	if (prec == 0 && idx == BUFF_SIZE - 2 && buff[idx] == '0')
		buff[idx] = pad = ' ';

	if (prec > 0 && prec < len)
		pad = ' ';
	while (prec > len)
		buff[--idx] = '0', len++;
	if (flag != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buff[i] = pad;
		buff[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (flag)
				buff[--idx] = flag;
			return (write(1, &buff[idx], len) + write(1, &buff[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (flag)
				buff[--idx] = flag;
			return (write(1, &buff[1], i - 1) + write(1, &buff[idx], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (flag)
				buff[--p] = flag;
			return (write(1, &buff[p], i - p) + write(1, &buff[idx], len - (1 - p)));
		}
	}
	if (flag)
		buff[--idx] = flag;
	return (write(1, &buff[idx], len));
}

/**
 * output_number - Prints a string
 * @is_neg: List of arguments
 * @idx: Index of the number in the buffer
 * @buffer: local buffer of 1024 chars
 * @flags: flag characters for non-custom conversion specifiers.
 * @width: width for non-custom conversion specifiers.
 * @prec: precision for non-custom conversion specifiers.
 * @size: Computed size
 *
 * Return: the number of characters printed
 */
int output_number(int is_neg, int idx, char buffer[],
				  int flags, int width, int prec, int size)
{
	int len = BUFF_SIZE - idx - 1;
	char pad = ' ', flag = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_neg)
		flag = '-';
	else if (flags & F_PLUS)
		flag = '+';
	else if (flags & F_SPACE)
		flag = ' ';
	return (output_buffer_number(idx, buffer, flags, width, prec,
								 len, pad, flag));
}

/**
 * etch_integer - Print int
 * @args: List of arguments
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers.
 * @prec: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: the number of characters printed
 */
int etch_integer(va_list args, char buffer[],
				 int flags, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = cast_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (output_number(is_neg, i, buffer, flags, width, prec, size));
}
