#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: is a character string.
 * Return:the number of characters printed (excluding '\0')
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	char *out_str, *s_conv;
	va_list args;
	params_t params = PARAMS_ZERO;

	va_start(args, format);
	if (!format || format[0] == '%' && !format[1])
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return(-1);

	for (out_str = (char*)format; *out_str; out_str++)
	{
		init_params(&params, args);
		if (*out_str != '%')
		{
			counter += (_putchar(*out_str));
			continue;
		}
		s_conv = out_str;
		out_str++;
		else 
			counter += 

	va_end(args);

	write(1, out_str, counter);
	return (counter);
}

