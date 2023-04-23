#include "main.h"

/**
 * handler - Format controller
 * @formatPtr: String format
 * @argList: List of arguments
 *
 * Return: Total size of arguments with the total size of the base string
 **/
int handler(const char *formatPtr, va_list argList)
{
	int argsLength, i, aux;

	argsLength = 0;
	for (i = 0; formatPtr[i] != 0; i++)
	{
		if (formatPtr[i] == '%')
		{
			aux = handle_format(formatPtr, argList, &i);
			if (aux == -1)
				return (-1);

			argsLength += aux;
			continue;
		}

		_putchar(formatPtr[i]);
		argsLength = argsLength + 1;
	}

	return (argsLength);
}

/**
 * handle_format - function to handle % + ?
 * @formatPtr: Pointer to format
 * @argList: List of arguments to handle
 * @i: Iterator
 *
 * Return: Size of the numbers of elements printed
 **/
int handle_format(const char *formatPtr, va_list argList, int *i)
{
	int argsLength, j, nFormats;
	format cases[] = {
		{'s', etch_string},
		{'c', etch_char},
		{'d', etch_integer},
		{'i', etch_integer},
		{'b', etch_binary},
		{'u', etch_unsigned},
		{'o', etch_octal},
		{'x', etch_hexadecimal},
		{'X', etch_Hexadecimal},
		{'p', etch_pointer},
		{'r', etch_reverse},
		{'R', etch_rot},
	};

	*i += 1;
	if (formatPtr[*i] == '\0')
		return (-1);

	if (formatPtr[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	nFormats = sizeof(cases) / sizeof(cases[0]);
	for (argsLength = j = 0; j < nFormats; j++)
	{
		if (formatPtr[*i] == cases[j].type)
		{
			argsLength = cases[j].f(argList);
			return (argsLength);
		}
	}

	_putchar('%'), _putchar(formatPtr[*i]);
	return (2);
}
