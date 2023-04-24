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
	const char *tar;

	tar = va_arg(argList, const char *);

	argLength = _strlen(tar);

	for (pos = argLength - 1; pos >= 0; pos--)
		_putchar(tar[pos]);

	return (argLength);
}
