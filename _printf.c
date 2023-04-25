#include "main.h"
/**
 * _printf - function that produces output according to a format c, s and %
 * @format: is a character string.
 * Return:the number of characters printed (excluding '\0')
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	char *out_str, *s;
	va_list args;

	va_start(args, format);
	if (!format || format[0] == '%' && format[1] == 
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

