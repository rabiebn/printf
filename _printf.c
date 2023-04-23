#include "main.h"
/**
 * _printf - function that produces output according to a format c, s and %
 * @format: is a character string.
 * Return:the number of characters printed (excluding '\0')
 */
int _printf(const char *format, ...)
{
	int i, j, counter = 0;
	char *out_str, *s;
	va_list args;

	out_str = malloc(sizeof(char) * (strlen(format) + 1));
	if (out_str == NULL)
	{
		return (-1); /*return -1 to indicate error*/
	}
	va_start(args, format);
	for (i = 0, j = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				*(out_str + j) = (char) va_arg(args, int);
				counter++;
				j++;
			}
			if (format[i + 1] == 's')
			{
				s = va_arg(args, char *);
				while (*s != '\0')
				{
					*(out_str + j) = *s;
					counter++;
					j++;
					s++;
				}
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
			*(out_str + j) = format[i];
			counter++;
			j++;
		}
	}
	*(out_str + j) = '\0';
	write(1, out_str, counter);
	free(out_str);
	va_end(args);
	return (counter);
}

