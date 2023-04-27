#include "main.h"

/**
 * etch_rot13 - Print a string in rot13.
 * @args: List of arguments
 * @buffer: local buffer of 1024 chars
 * @flags:  flag characters for non-custom conversion specifiers
 * @width: width for non-custom conversion specifiers
 * @precision: precision for non-custom conversion specifiers.
 * @size: Computed size specifier
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int etch_rot13(va_list args, char buffer[],
			   int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
