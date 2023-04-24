#include "main.h"

/**
 * format_str - helper function that formats a string
 * @args: list of arguments
 * Return: string
 */
char *format_str(va_list args)
{
	char *s;
	char *p;

	s = va_arg(args, char *);

	p = malloc(sizeof(char) * (_strlen(s) + 1));
	if (p == NULL)
		return (NULL);

	_strcpy(p, s);
	return (p);
}
