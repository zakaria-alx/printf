#include "main.h"

/**
 * etch_reverse - Print a string in reverse
 * @argList: String to print in reverse
 *
 * Return: Length of the string
 **/
int etch_reverse(va_list argList)
{
	int pos, argLength;
	const char *str;

	str = va_arg(argList, const char *);

	argLength = _strlen(str);

	for (pos = argLength - 1; pos >= 0; pos--)
		_putchar(str[pos]);

	return (argLength);
}
