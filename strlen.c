#include "main.h"

/**_strlen - calculates the length of a string
 * @s: string
 * Return: length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*(s + len))
		len++;

	return (len);
}
