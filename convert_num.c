#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @args: the argument pointer
 * @par: the parameters struct
 * Return: number of bytes printed
 */
int print_hex(va_list args, params_t par)
{
	unsigned long l;
	int c = 0;
	char *s;

	if (par.l_mod)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (par.h_mod)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	s = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	if (par.hashtag_flag && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	par.unsign = 1;
	return (c += print_number(s, par));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @args: the argument pointer
 * @par: the parameters struct
 * Return: number of bytes printed
 */
int print_HEX(va_list args, params_t par)
{
	unsigned long l;
	int c = 0;
	char *s;

	if (par.l_mod)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (par.h_mod)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	s = convert(l, 16, CONVERT_UNSIGNED, par);
	if (par.hashtag_flag && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	par.unsign = 1;
	return (c += print_number(s, par));
}

/**
 * print_binary - prints unsigned binary number
 * @args: the argument pointer
 * @par: the parameters struct
 * Return: bytes printed
 */
int print_binary(va_list args, params_t par)
{
	unsigned int n = va_arg(args, unsigned int);
	char *s = convert(n, 2, CONVERT_UNSIGNED, par);
	int c = 0;

	if (par.hashtag_flag && n)
		*--s = '0';
	par.unsign = 1;
	return (c += print_number(s, par));
}

/**
 * print_octal - prints unsigned octal numbers
 * @args: the argument pointer
 * @par: the parameters struct
 * Return: bytes printed
 */
int print_octal(va_list args, params_t par)
{
	unsigned long l;
	char *s;
	int c = 0;

	if (par.l_mod)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (par.h_mod)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	s = convert(1, 8, CONVERT_UNSIGNED, par);
	if (par.hashtag_flag && 1)
		*--s = '0';
	par.unsign = 1;
	return (c += print_number(s, par));
}
