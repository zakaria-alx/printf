#include "main.h"

/**
 * etch_pointer - Prints the value of a pointer variable
 * @args: List a of arguments
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: the number of characters printed.
 */
int etch_pointer(va_list args, char buffer[],
				 int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (output_pointer(buffer, ind, length,
						   width, flags, padd, extra_c, padd_start));
}

/**
 * output_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @idx: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: flag characters for non-custom conversion specifiers specifier
 * @pad: Char representing the padding
 * @flag: Char representing extra char
 * @start_pad_at: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int output_pointer(char buffer[], int idx, int length,
				   int width, int flags, char pad, char flag, int start_pad_at)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = pad;

		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--idx] = 'x';
			buffer[--idx] = '0';
			if (flag)
				buffer[--idx] = flag;
			return (write(1, &buffer[idx], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--idx] = 'x';
			buffer[--idx] = '0';
			if (flag)
				buffer[--idx] = flag;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[idx], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (flag)
				buffer[--start_pad_at] = flag;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[start_pad_at], i - start_pad_at) +
					write(1, &buffer[idx], length - (1 - start_pad_at) - 2));
		}
	}
	buffer[--idx] = 'x';
	buffer[--idx] = '0';
	if (flag)
		buffer[--idx] = flag;
	return (write(1, &buffer[idx], BUFF_SIZE - idx - 1));
}
