#include "main.h"

/**
 * print_number - prints a number according to options
 * @s: base number as a string
 * @par: parameters struct
 * Return: number of bytes printed
 */
int print_number(char *s, params_t par)
{
	unsigned int i = _strlen(s);
	int is_neg = (!par.unsign && *s == '-');

	if (!par.percision && *s == '0' && !s[1])
		s = "";
	if (is_neg)
	{
		s++;
		i--;
	}
	if (par.percision != UNIT_MAX)
		while (i++ < par.percision)
			*--s = '0';
	if (is_neg)
		*--s = '-';

	if (!par.minus_flag)
		return (print_number_right_shift(s, par));
	else
		return (print_number_left_shift(s, par));
}

/**
 * print_number_right_shift - prints a number with options
 * @s: the base number as a string
 * @par: parameter struct
 * Return: number of bytes printed
 */
int print_number_right_shift(char *s, params_t par)
{
	unsigned int n = 0, is_neg, is_neg2, i = _strlen(s);
	char pad_char = ' ';

	if (par.zero_flag && !par.minus_flag)
		pad_char = '0';
	is_neg = is_neg2 = (!par.unsign && *s == '-');
	if (is_neg && i < par.width && pad_char == '0' && !par.minus_flag)
		s++;
	else
		is_neg = 0;
	if ((par.plus_flag && !is_neg2) ||
			(!par.plus_flag && par.space_flag && !is_neg2))
		i++;
	if (is_neg && pad_char == '0')
		n += _putchar('-');
	if (par.plus_flag && !is_neg2 && pad_char == '0' && !par.unsign)
		n += _putchar('+');
	else if (!par.plus_flag && par.space_flag && !is_neg2 &&
			!par.unsign && par.zero_flag)
		n += _putchar(' ');
	while (i++ < par.width)
		n += _putchar(pad_char);
	if (is_neg && pad_char == ' ')
		n += _putchar('-');
	if (par.plus_flag && !is_neg2 && pad_char == ' ' && !par.unsign)
		n += _putchar('+');
	else if (!par.plus_flag && par.space_flag && !is_neg2 &&
			!par.unsign && par.zero_flag)
		n += _putchar(' ');
	n += _putstr(s);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @s: the base number as a string
 * @par: parameter struct
 * Return: number of bytes printed
 */
int print_number_left_shift(char *s, params_t par)
{
	unsigned int n = 0, is_neg, is_neg2, i = _strlen(s);
	char pad_char = ' ';

	if (par.zero_flag && !par.minus_flag)
		pad_char = '0';
	is_neg = is_neg2 = (!par.unsign && *s == '-');
	if (is_neg && i < par.width && pad_char == '0' && !par.minus_flag)
		s++;
	else
		is_neg = 0;

	if (par.plus_flag && !is_neg2 && !par.unsign)
		n += _putchar('+'), i++;
	else if (par.space_flag && !is_neg2 && !par.unsign)
		n += _putchar(' '), i++;
	n += _putstr(s);
	while (i++ < par.width)
		n += _putchar(pad_char);
	return (n);
}

/**
 * print_S - custom format specifier
 * @args: argument pointer
 * @par: the parameters struct
 * Return: number chars printed
 */
int print_S(va_list args, params_t par)
{
	char *s = va_arg(args, char *);
	char *hex;
	int counter = 0;

	if ((int)(!s))
		return (_putstr("(null)"));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			counter += _putchar('\\');
			counter += _putchar ('x');
			hex = convert(*s, 16, 0, par);
			if (!hex[1])
				counter += _putchar ('0');
			counter += _putstr(hex);
		}
		else
		{
			counter += _putchar(*s);
		}
	}
	return (counter);
}
