#include "main.h"

/**
 * etch_hexadecimal - Print a number in lowercase hexadecimal format
 * @argList: Number to print
 *
 * Return: Length of the number
 **/
int etch_hexadecimal(va_list argList)
{
	char *buffPtr;
	int argsLength;

	buffPtr = convert_ascii(va_arg(argList, unsigned int), 16);

	argsLength = etch((buffPtr != NULL) ? buffPtr : "NULL");

	return (argsLength);
}
