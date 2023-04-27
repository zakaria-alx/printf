#include "main.h"

/**
 * output_unsigned_int - Writes an unsigned number
 * @is_neg: 1 is negative, 0 if not
 * @idx: Index of the number in the buffer
 * @buffer: local buffer of 1024 chars
 * @flags: flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size
 *
 * Return: Number of written chars.
 */
int output_unsigned_int(int is_neg, int idx,
						char buffer[],
						int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - idx - 1, i = 0;
	char pad = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
		return (0);

	if (precision > 0 && precision < length)
		pad = ' ';

	while (precision > length)
	{
		buffer[--idx] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = pad;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[idx], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[idx], length));
		}
	}

	return (write(1, &buffer[idx], length));
}
