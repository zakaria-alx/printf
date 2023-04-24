#include "main.h"

/**
 * convert_ascii - Convert integer to ascii value
 * @number: number to convert
 * @base: base to convert to
 *
 * Return: Length of the character
 *
 **/
char *convert_ascii(long int number, int base)
{
	static char *arr = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *lengthPtr;
	unsigned long n = number;

	if (number < 0)
	{
		n = -number;
		sign = '-';
	}
	lengthPtr = &buffer[49];
	*lengthPtr = '\0';

	do {
		*--lengthPtr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--lengthPtr = sign;
	return (lengthPtr);
}
