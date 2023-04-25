#include "main.h"

/**
 * get_specifier - gets the format function
 * @s: format string
 * Return: number of bytes printed
 */
int (*get_specifier(char *s))(va_list args, params_t par)
{
	printf_t specifier[] = {
		{"c", format_char},
		{"s", format_str},
		{"%", format_percent},
		/* I'm gonna add more structs here*/
		{NULL, NULL}
	};
	int i = 0;

	while (specifier[i].identifier)
	{
		if (*s == specifier[i].identifier[0])
			return (specifier[i].func);
		i++;
	}
	return (NULL);
}

/**
 * get_func - gets the format function
 * @s: format string
 * @args: arguments' pointer
 * @par: the parameters struct
 * Return: the number of bytes printed
 */
int get_func(char *s, va_list args, __attribute__((unused)) params_t par)
{
	int (*func)(va_list, params_t) = get_specifier(s);

	if (func)
		return (func(args, par));
	return (0);
}

/**
 * get_flag - gets the flag function
 * @s: format string
 * @par: parameters struct
 * Return: if flag was specified
 */
int get_flag(char *s, params_t par)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = par.plus_flag = 1;
			break;
		case ' ':
			i = par.space_flag = 1;
			break;
		case '#':
			i = par.hashtag_flag = 1;
			break;
		case '0':
			i = par.zero_flag = 1;
			break;
		case '-':
			i = par.minus_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - gets the modifier function
 * @s: format string
 * @par: parameters struct
 * Return: if modifier was specified
 */
int get_modifier(char *s, params_t par)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = par.h_mod = 1;
			break;
		case 'l':
			i = par.l_mod = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: format string
 * @par: parameters struct
 * @args: arguments' pointer
 * Return: pointer
 */
char *get_width(char *s, __attribute__((unused)) params_t par, va_list args)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	par.width = i;
	return (s);
}

/**
 * get_percision - gets the percision from format
 * @s: format string
 * @par: parameters struct
 * @args: arguments' pointer
 * Return: pointer
 */
char *get_percision(char *s, __attribute__((unused)) params_t par,
		va_list args)
{
	int i = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		i = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	par.percision = i;
	return (s);
}
