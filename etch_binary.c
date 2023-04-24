#include "main.h"

/**
 * etch_binary - Print a number in base 2
 * @argList: Number to print in base 2
 *
 * Return: Length of the numbers in binary
 **/
int etch_binary(va_list argList)
{
	char *buffPtr;
	int argLength;

	buffPtr = convert_ascii(va_arg(argList, unsigned int), 2);
	argLength = etch(buffPtr);

	return (argLength);
}
