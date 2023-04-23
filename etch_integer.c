#include "main.h"

/**
 * etch_integer - Print a number in base 10
 * @argList: Number to print in base 10
 *
 * Return: Length of the numbers in decimal
 **/
int etch_integer(va_list argList)
{
	char *buffPtr;
	int argsLength;

	buffPtr = convert_ascii(va_arg(argList, int), 10);

	argsLength = etch((buffPtr != NULL) ? buffPtr : "NULL");

	return (argsLength);
}
