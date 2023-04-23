#include "main.h"

/**
 * _putchar - Redirect character to buffer of size 1024 instead of write
 * @character: The character to save
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char character)
{
	return (buffer(character));
}
