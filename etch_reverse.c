#include "main.h"

/**
 * etch_reverse - Print a string in reverse
 * @argList: String to print in reverse
 *
 * Return: Length of the string
 **/
int etch_reverse(va_list argList)
{
	int pos, argsLength;
	const char *str;

	str = va_arg(argList, const char *);

	argsLength = _strlen(str);

	for (pos = argsLength - 1; pos >= 0; pos--)
		_putchar(str[pos]);

	return (argsLength);
}
