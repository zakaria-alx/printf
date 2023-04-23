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

/**
 * put_hex_upper - function that prints the hex number.
 * @num: target number.
 * @ptr_score: a pointer to an integer that keeps track of the number
 * of integers printed so far.
 *
 * Return: 1 or 0 if no num found.
 **/
int _puthex(int num)
{
	int ptr_score = 0;
	char buffer[32];
	int i, count = 0;
	char hex_digits[] = "0123456789ABCDEF";

	if (num == 0)
	{
		_putchar('0');
		ptr_score++;
		return (1);
	}

	i = 0;
	while (num > 0)
	{
		buffer[i] = hex_digits[num % 16];
		num /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(buffer[i]);
		i--;
		ptr_score++;
		count++;
	}
	return (ptr_score);
}

int etch_String(va_list argList)
{
	int idx;
	int ptr_score = 0;
	char *str = va_arg(argList, char *);

	if (str == NULL)
		str = "(null)";

	for (idx = 0; str[idx] != '\0'; idx++)
	{
		if ((str[idx] > 0 && str[idx] < 32) || str[idx] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			ptr_score += 2;
			if (str[idx] < 16)
			{
				_putchar('0');
				ptr_score += 1;
			}
			ptr_score += _puthex(str[idx]);
		}
		else
		{
			_putchar(str[idx]);
			ptr_score += 1;
		}
	}
	return (ptr_score);
}