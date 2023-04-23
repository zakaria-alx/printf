#include "main.h"

/**
 * etch - print function inspired from python.
 * @charPtr: pointer to string.
 *
 * Return: Length of the string.
 */

int etch(char *charPtr)
{
	int argLength;

	for (argLength = 0; charPtr[argLength] != '\0'; ++argLength)
		_putchar(charPtr[argLength]);

	return (argLength);
}
