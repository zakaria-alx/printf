#include "main.h"

/**
 * etch_string - Print string
 * @argList: String to print.
 *
 * Return: Length of the string.
 */

int etch_string(va_list argList)
{
	char *argPtr;
	int argLength;

	argPtr = va_arg(argList, char *);
	argLength = etch((argPtr != NULL) ? argPtr : "(null)");

	return (argLength);
}
