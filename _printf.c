#include "main.h"

/**
 * _format - helper function that formats the output
 * @out_str: pointer to the output string buffer
 * @format: pointer to the format string
 * @args: variable list arguments
 * Return:the number of characters printed (excluding '\0')
 */
int _format(char *out_str, const char *format, va_list args)
{
	int i, j, counter = 0;

	for (i = 0, j = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			_strcpy(out_str + j, get_func(format[i + 1])(args));
			counter += _strlen(out_str + j);
			if (out_str == NULL)
				i++; /*skip over the conversion specifier*/
		}
		else
		{
			out_str[j] = format[i];
			counter++;
		}
		j++;
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

	out_str = malloc(sizeof(char) * (_strlen(format) + 1));
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
