#include "main.h"
/**
 * _format_char - helper function that formats a single character
 * @out_str: pointer to the output string buffer
 * @c: the character to format
 * Return: the number of characters printed (always 1)
 */
static int _format_char(char *out_str, char c)
{
	*out_str = c;
	return (1);
}
/**
 * _format_str - helper function that formats a string
 * @out_str: pointer to the output string buffer
 * @s: the string to format
 * Return: the number of characters printed (always 1)
 */
static int _format_str(char *out_str, const char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		*out_str = *s;
		counter++;
		out_str++;
		s++;
	}
	*out_str = '\0';
	return (counter);
}
/**
 * _format - helper function that formats the output
 * @out_str: pointer to the output string buffer
 * @format: pointer to the format string
 * @args: variable list arguments
 * Return:the number of characters printed (excluding '\0')
 */
static int _format(char *out_str, const char *format, va_list args)
{
	int i, j, counter = 0;
	char *s;

	for (i = 0, j = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				counter += _format_char(out_str + j,
				(char) va_arg(args, int));
				j++;
			}
			if (format[i + 1] == 's')
			{
				s = va_arg(args, char *);
				counter += _format_str(out_str + j, s);
				j += strlen(s);
			}
			if (format[i + 1] == '%')
			{
				*(out_str + j) = '%';
				counter++;
				j++;
			}
			i++; /*skip over the conversion specifier*/
		}
		else
		{
			counter += _format_char(out_str + j, format[i]);
			j++;
		}
	}
	return (counter);
}

/**
 * _printf - function that produces output according to a format c, s and %
 * @format: is a character string.
 * Return:the number of characters printed (excluding '\0')
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	char *out_str;
	va_list args;

	out_str = malloc(sizeof(char) * (strlen(format) + 1));
	if (out_str == NULL)
	{
		return (-1); /*return -1 to indicate error*/
	}
	va_start(args, format);
	counter = _format(out_str, format, args);
	va_end(args);

	write(1, out_str, counter);
	free(out_str);

	return (counter);
}
