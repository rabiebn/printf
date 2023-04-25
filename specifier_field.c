#include "main.c"
/**
 * get_specifier - find format function equivalent
 * @s: the format string
 * @args: arguments
 * @params: pointer to params_t
 * Return: int number of bytes printed 
 */
int (*get_specifier(char *s))(va_list args, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", format_char},
		{"s", format_str},
		{"%", format_percent}i
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
int get_print_func(char *s, 


