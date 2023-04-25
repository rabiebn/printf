#include "main.h"
/**
 * format_char - helper function that formats a single character
 * @args: argument pointer
 * @params: the parameters struct
 * Return: the number of characters printed
 */
int format_char(va_list args, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, counter = 0, c = va_arg(args, int);

	if (params->minus_flag)
		counter += _putchar(c);
	while (pad++ < params->width)
		counter += _putchar(pad_char);
	if (!params->minus_flag)
		counter += _putchar(c)
	return (counter);
}
/**
 * format_str - helper function that formats a string
 * @args: argument pointer
 * @params: the parameters struct
 * Return: the number of characters printed
 */
int format_str(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char pad_char = ' ';
	unsigned int pad = 0, counter = 0, i = 0, j;
	(void)params;

	switch ((int)(!str))
	case 1:
		str = EMPTY_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;



















}
