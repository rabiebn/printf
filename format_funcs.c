#include "main.h"

/**
 *  * _strlen - calculates the length of a string
 *   * @s: string
 *    * Return: length of the string
 *     */
int _strlen(const char *s)
{
	int len = 0;

	while (*(s + len))
		len++;

	return (len);
}

/**
 *  * _isdigit - checks if char is digit
 *   * @c: char to check
 *    * Return: 1 if digit, 0 if not
 *    */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 *  * format_char - 
 *  */
int format_char(va_list args, params_t par)
{
	char pad_char = ' ';
	unsigned int pad = 1, counter = 0, c = va_arg(args, int);

	if (par.minus_flag)
		counter += _putchar(c);
	while (pad++ < par.width)
		counter += _putchar(pad_char);
	if (!par.minus_flag)
		counter += _putchar(c);

	return (counter);
}

/**
 *  * format_str - prints string
 *   * @args: argument pointer
 *    * @par: parameters struct
 *     * Return: number of bytes printed
 *     */
int format_str(va_list args, params_t par)
{
	char *s = va_arg(args, char *), space_char = ' ';
	unsigned int pad = 0, counter = 0, i = 0, j = 0;

	(void)par;
	switch ((int)(!s))
	{
		case 1:
			s = "(null)";
	}

	j = pad = _strlen(s);
	if (par.percision < pad)
		j = pad = par.percision;

	if (par.minus_flag)
	{
		if (par.percision != UINT_MAX)
			for (i = 0; i < pad; i++)
				counter += _putchar(*s++);
		else
			counter += _putstr(s);
	}
	while (j++ < par.width)
		counter += _putchar(space_char);
	if (!par.minus_flag)
	{
		if (par.percision != UINT_MAX)
			for (i = 0; i < pad; i++)
				counter += _putchar(*s++);
		else
			counter += _putstr(s);
	}
	return (counter);
}

/**
 *  * format_percent - prints %
 *   * @args: argument pointer
 *    * @par: parameters struct
 *     * Return: number of bytes printed
 *     */
int format_percent(va_list args, params_t par)
{
	(void)args;
	(void)par;
	return (_putchar('%'));
}
