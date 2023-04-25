#include "main.h"

/**
 * _putchar - prints a char
 * @c: char to print
 * Return: on success 1,
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(char c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putstr - prints a string using _putchar
 * @s: string to print
 * Return: number of characters printed
 */
int _putstr(char *s)
{
	int i = 0;

	while (*s)
	{
		_putchar(*s);
		i++;
		s++;
	}
	return (i);
}
