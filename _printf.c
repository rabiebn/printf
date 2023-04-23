#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int i, counter = 0;
	char *out_str;
	va_list args;

	out_str = malloc(sizeof(*format));
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				*(out_str + i) = (char) va_arg(args, int);
				counter++;
			}
			if (format[i + 1] == 's')
			{
				int j = 0;
				char *s;

				s = va_arg(args, char *);
				while(*(s + j) != '\0')
				{
					*(out_str + i) = *(s + j);
					counter++;
					j++;
				}
			}
			if (format[i + 1] == '%')
			{
				*(out_str + i) = '%';
				counter++;
			}
		}
		*(out_str + i) = (char) va_arg(args, int);
		counter += 2;
	}
	*(out_str + i) = '\0';
	write(1, out_str, counter);
	free(out_str);
	va_end(args);
	return (counter);
}
