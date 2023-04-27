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

/**
 * print_rev - prints string in reverse
 * @args: argument pointer
 * @par: parameters struct
 * Return: number of bytes printed
 */
int print_rev(va_list args, params_t par)
{
	int len, counter = 0;
	char *s = va_arg(args, char *);
	(void)par;

	if (s)
	{
		for (len = 0; *s; s++)
			len++;
		s--;
		for (; len > 0; len--, s--)
			counter += _putchar(*s);
	}
	return (counter);
}

/**
 * print_rot13 - prints string in rot13
 * @args: argument pointer
 * @par: parameters struct
 * Return: number of bytes printed
 */
int print_rot13(va_list args, params_t par)
{
	int i = 0, j = 0, counter = 0;
	char rot13[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(args, char *);
	(void)par;

	while (s[i])
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') ||
				(s[i] >= 'a' && s[i] <= 'z'))
		{
			j = s[i] - 65;
			counter += _putchar(rot13[j]);
		}
		else
			counter += _putchar(s[i]);
		i++;
	}
	return (counter);
}
