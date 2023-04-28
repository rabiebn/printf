#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: is a character string.
 * Return:the number of characters printed (excluding '\0')
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *out_str, *s;
	int counter = 0;
	params_t par = PARAMS_ZERO;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (out_str = (char *)format; *out_str; out_str++)
	{
		set_params_to_zero(&par, args);
		if (*out_str != '%')
		{
			counter += _putchar(*out_str);
			continue;
		}
		s = out_str;
		out_str++;
		while (get_flag(out_str, par))
		{
			out_str++;
		}
		out_str = get_width(out_str, par, args);
		out_str = get_percision(out_str, par, args);
		if (get_modifier(out_str, par))
			out_str++;
		if (!get_specifier(out_str))
			counter += print_from_to(s, out_str,
					par.l_mod || par.h_mod ?
					out_str - 1 : 0);
		else
			counter += get_func(out_str, args, par);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (counter);
}
