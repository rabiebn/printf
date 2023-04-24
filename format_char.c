#include "main.h"

/**
 * format_char - helper function that formats a single character
 * @args: list of arguments
 * Return: char as a string
 */
char *format_char(va_list args)
{
	char *s;
	char c;

	c =(char) va_arg(args, int);

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);

	s[0] = c;
	s[1] = '\0';

	return (s);
}
