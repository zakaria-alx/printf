#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, idx;
	int flagg = 0;

	Flag flags[] = {
		{MINUS, F_MINUS},
		{PLUS, F_PLUS},
		{ZERO, F_ZERO},
		{HASH, F_HASH},
		{SPACE, F_SPACE},
		{'\0', F_NULL},
	};

	for (idx = *i + 1; format[idx] != '\0'; idx++)
	{
		for (j = 0; flags[j].flag != '\0'; j++)
		{
			if (format[idx] == flags[j].flag)
			{
				flagg |= flags[j].repr;
				break;
			}
		}

		if (flags[j].flag == '\0')
			break;
	}

	*i = idx - 1;

	return (flagg);
}

/**
 * get_precision - Calculates the precision for printing
 * @format: is a character string.
 * The format string is composed of zero or more directives
 * @i: List of arguments to be printed.
 * @args: List of arguments to be printed..
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list args)
{
	int idx = *i + 1;
	int precision = -1;

	if (format[idx] != '.')
	{
		return (precision);
	}

	precision = 0;

	for (idx += 1; format[idx] != '\0'; idx++)
	{
		if (is_digit(format[idx]))
		{
			precision *= 10;
			precision += format[idx] - '0';
		}
		else if (format[idx] == '*')
		{
			idx++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = idx - 1;

	return (precision);
}

/**
 * get_size - Calculates the size to cast the argument
 * @format: is a character string.
 * The format string is composed of zero or more directives
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int idx = *i + 1;
	int size = 0;

	if (format[idx] == 'l')
	{
		size = S_LONG;
	}
	else if (format[idx] == 'h')
	{
		size = S_SHORT;
	}

	if (size == 0)
	{
		*i = idx - 1;
	}
	else
	{
		*i = idx;
	}

	return (size);
}

/**
 * get_width - Calculates the width for printing
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 * @i: List of arguments to be printed.
 * @args: List of arguments to be printed..
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list args)
{
	int idx;
	int width = 0;

	for (idx = *i + 1; format[idx] != '\0'; idx++)
	{
		if (is_digit(format[idx]))
		{
			width *= 10;
			width += format[idx] - '0';
		}
		else if (format[idx] == '*')
		{
			idx++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = idx - 1;

	return (width);
}
