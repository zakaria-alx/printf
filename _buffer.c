#include "main.h"

/**
 * buffer - Save the character to 1024 buffer
 * @character: Character to save in buffer
 *
 * Return: 1
 **/
int buffer(char character)
{
	static char buff[1024];
	static int i;

	if (character == -1 || i == 1024)
	{
		write(1, buff, i);
		i = 0;
	}

	if (character != -1)
	{
		buff[i++] = character;
	}

	return (1);
}
