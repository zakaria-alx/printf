#include "main.h"

int is_lowercase(char);
char *string_to_upper(char *);

/**
 * etch_Hexadecimal - Print a number in uppercase hexadecimal format
 * @argList: Number to print
 *
 * Return: Length of the number
 **/
int etch_Hexadecimal(va_list argList)
{
	char *buffPtr;
	int argsLength;

	buffPtr = convert_ascii(va_arg(argList, unsigned int), 16);
	buffPtr = string_to_upper(buffPtr);

	argsLength = etch((buffPtr != NULL) ? buffPtr : "NULL");

	return (argsLength);
}

/**
 * is_lowercase - Check if the character are in lowercase
 * @c: Character
 * Return: 1 or 0
 **/
int is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * string_to_upper - Change the string to uppercase
 * @s: String
 * Return: String uppercase
 **/
char *string_to_upper(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_lowercase(s[i]))
		{
			s[i] = s[i] - 32;
		}
	}

	return (s);
}
