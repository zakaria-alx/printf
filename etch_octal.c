#include "main.h"

/**
 * etch_octal - Print a unsigned octal
 * @argList: Number to print
 *
 * Return: Length of the number
 **/
int etch_octal(va_list argList)
{
	char *buffPtr;
	int argsLength;

	buffPtr = convert_ascii(va_arg(argList, unsigned int), 8);

	argsLength = etch((buffPtr != NULL) ? buffPtr : "NULL");

	return (argsLength);
}
