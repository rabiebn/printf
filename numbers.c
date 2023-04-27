#include "main.h"

/**
 * convert - converter
 * @num: number
 * @base: base
 * @flags: arg flags
 * @par: parameters struct
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t par)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;
	(void)par;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ?
		"0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do {
		*--p = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * print_unsigned - prints unsigned int
 * @args: argument pointer
 * @par: the parameters struct
 * Return: number of bytes printed
 */
int print_unsigned(va_list args, params_t par)
{
	unsigned long l;

	if (par.l_mod)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (par.h_mod)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	par.unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, par), par));
}

/**
 * print_address - prints address
 * @args: argument pointer
 * @par: the parameters struct
 * Return: number of bytes printed
 */
int print_address(va_list args, params_t par)
{
	unsigned long int n = va_arg(args, unsigned long int);
	char *s;

	if (!n)
		return (_putstr("(nil)"));

	s = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, par));
}
