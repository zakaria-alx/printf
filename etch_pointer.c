#include "main.h"
#include <stdio.h>

int _strcmp(char *, char *);

/**
 * etch_pointer - Print a number in hexadecimal format
 * @argList: Number to print
 *
 * Return: Length of the number
 **/
int etch_pointer(va_list argList)
{
	char *buffPtr;
	int argsLength;

	buffPtr = convert_ascii(va_arg(argList, unsigned long int), 16);

	if (!_strcmp(buffPtr, "0"))
		return (etch("(nil)"));

	argsLength = etch("0x");

	if (!_strcmp(buffPtr, "-1"))
		argsLength += etch("ffffffffffffffff");
	else
		argsLength += etch(buffPtr);

	return (argsLength);
}

/**
 * _strcmp - Compare two strings
 * @s1: String 1
 * @s2: String 2
 * Return: Integer
 **/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}
