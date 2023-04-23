#include "main.h"
/**
 * etch_unsigned - Print a unsigned int
 * @argList: Number to print
 *
 * Return: Length of the number
 **/
int etch_unsigned(va_list argList)
{
	char *buffPtr;
	int argsLength;

	buffPtr = convert_ascii(va_arg(argList, unsigned int), 10);

	argsLength = etch((buffPtr != NULL) ? buffPtr : "NULL");

	return (argsLength);
}
