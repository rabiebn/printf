#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: pointer to the copy
 * @src: pointer to the string to copy
 *
 */
void _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}
