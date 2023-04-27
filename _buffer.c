
#include "main.h"

/**
 * buffer - Save the character to 1024 buffer
 * @character: Character to save in buffer
 *
 * Return: 1
 **/
int buffer(char character)
{
	static char buff[BUFF_SIZE];
	static int idx;

	if (character == -1 || idx == BUFF_SIZE)
	{
		write(1, buff, idx);
		idx = 0;
	}

	if (character != -1)
	{
		buff[idx++] = character;
	}

	return (1);
}