#include "main.h"

int _putint(unsigned int arg)
{
	int ptr_score = 0;

	/* To check whether an unsigned integer is negative, */
	/* you can check its most significant bit (MSB),*/
	/* which is the 31st bit in a 32-bit unsigned integer.*/
	/* The MSB is set to 1 if the number is negative,*/
	/* and set to 0 if it's non-negative. */
	if (arg & (1 << 31))
	{
		/* Print '-' to indicate that arg is a negative unsigned int. */
		_putchar('-');

		/* Update counter */
		ptr_score += 1;

		/* Multiply arg by -1 to make it positive */
		arg *= -1;
	}

	/* check if arg is not a single digit */
	if (arg / 10)
	{
		/* call the function again recusively if not a single digit */
		_putint(arg / 10);
		ptr_score += 1;
	}

	/* print the arg in ascii by adding 48 */
	_putchar(arg % 10 + '0');

	/* Update counter */
	ptr_score += 1;

	return (ptr_score);
}

/**
 * etch_integer - Print a number in base 10
 * @argList: Number to print in base 10
 *
 * Return: Length of the numbers in decimal
 **/
int etch_integer(va_list argList)
{
	int argsLength;

	argsLength = _putint(va_arg(argList, int));
	return (argsLength);
}
