#include "main.h"

/**
 * get_func - returns the function associated with the character after %
 * @c: format specifier
 * Return: function
 */
char * (*get_func(char c))(va_list)
{
	int i = 0;
	printf_t char_to_func[] = {
		{'c', format_char},
		{'s', format_str},
		{'%', format_percent},
		{'\0', NULL}
	};

	while (char_to_func[i].identifier != '\0')
	{
		if (c == char_to_func[i].identifier)
			return (char_to_func[i].func);
		i++;
	}

	return (NULL);
}
