#include "main.h"

/**
 * print_from_to - prints a range of characters
 * @s: starting address
 * @stop: stopping address
 * @except: except address
 * Return: number of bytes printed
 */
int print_from_to(char *s, char *stop, char *except)
{
	int counter = 0;

	while (s <= stop)
	{
		if (s != except)
			counter += _putchar(*s);
		s++;
	}
	return (counter);
}
