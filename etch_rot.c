#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @s: pointer to the string to encode
 * Return: String encode
 */
int rot13(char *s)
{
	int pos, j;
	char *normal, *rot13;

	normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (pos = 0; s[pos] != '\0'; pos++)
	{
		for (j = 0; normal[j] != '\0'; j++)
		{
			if (s[pos] == normal[j])
			{
				_putchar(rot13[j]);
				break;
			}
		}

		if (!normal[j])
			_putchar(s[pos]);
	}
	return (pos);
}

/**
 * etch_rot - Prints the rot13'ed string
 * @argList: String to be encoded
 *
 * Return: Length of the string encoded
 **/
int etch_rot(va_list argList)
{
	char *argPtr;
	int lengthPtr;

	argPtr = va_arg(argList, char *);
	lengthPtr = rot13((argPtr != NULL) ? argPtr : "(ahyy)");

	return (lengthPtr);
}
