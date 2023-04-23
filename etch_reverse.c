#include "main.h"

/**
 * etch_reverse - Print a string in reverse
 * @argList: String to print in reverse
 *
 * Return: Length of the string
 **/
int etch_reverse(va_list argList)
{
	int i, argsLength;
	const char *str;

	str = va_arg(argList, const char *);

	argsLength = _strlen(str);

	for (i = argsLength - 1; i >= 0; i--)
		_putchar(str[i]);

	return (argsLength);
}
