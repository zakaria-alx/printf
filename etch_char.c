#include "main.h"
/**
 * etch_char - Print character.
 * @argList: Character to print.
 *
 * Return: 1
 */
int etch_char(va_list argList)
{
	int _char;

	_char = va_arg(argList, int);

	_putchar(_char);

	return (1);
}
