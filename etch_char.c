#include "main.h"
/**
 * etch_char - Print character.
 * @argList: Character to print.
 *
 * Return: 1
 */
int etch_char(va_list argList)
{
	int charNum;

	charNum = va_arg(argList, int);

	_putchar(charNum);

	return (1);
}
