#include "main.h"

/**
 * _strlen - Compute the length of a string
 * @stringPtr: pointer to string
 *
 * Return: Length of the computed string
 **/
int _strlen(const char *stringPtr)
{
	int i;

	/* Increase i through forLoop */
	for (i = 0; stringPtr[i] != 0; i++)
		;

	return (i);
}
