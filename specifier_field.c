#include "main.c"
/**
 * get_specifier - find format function equivalent
 * @s: the format string
 * Return: int number of bytes printed
 */
int (*get_specifier(char *s))(va_list args, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", format_char},
		{"s", format_str},
		{"%", format_percent},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
			return (specifiers[i].f);
		i++;
	}
	return (NULL);
}
/**
 * get_print_func - finds the format function equivalent
 * @s: the format string
 * @args: arguments
 * @params: the parametres of struct
 * Return: int
 */

int get_print_func(char *s, va_list args, params_t *params)
{
	int (*f)(va_list, params_t *);

	if (f)
		return (f(args, params));
	return (0);
}

