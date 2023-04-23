#include "main.h"

/**
 * _printf - Custom printf function
 * @format: arguments to print.
 *
 * Return: length of arguments
 **/
int _printf(const char *format, ...)
{
	int argsLength;
	va_list args;

	if (format == NULL)
		return (-1);

	argsLength = _strlen(format);
	if (argsLength <= 0)
		return (0);

	va_start(args, format);
	argsLength = handler(format, args);

	_putchar(-1);
	va_end(args);

	return (argsLength);
}
