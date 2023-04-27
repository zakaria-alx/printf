#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format:  is a character string
 * @i: pointer.
 * Return: flags:
 */
int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_STR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_LST[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_STR[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_STR[j])
			{
				flags |= FLAGS_LST[j];
				break;
			}

		if (FLAGS_STR[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

/**
 * get_precision - Calculates the precision for printing
 * @format:  is a character string
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	curr_i++;
	if (format[curr_i] == '*')
	{
		curr_i++;
		precision = va_arg(list, int);
	}
	else
	{
		while (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
			curr_i++;
		}
	}

	*i = curr_i - 1;

	return (precision);
}

/**
 * get_size - Calculates the size to cast the argument
 * @format:  is a character string
 * @i: List of arguments to be printed.
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

/**
 * get_width - Calculates the width for printing
 * @format: is a character string
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int width = 0;

	for (; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			if (width < 0)
			{
				width = -width;
				break;
			}
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
