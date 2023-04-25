#include "main.c"
/**
 *
 *
 *
 */
int (*get_specifier_field(char *s))(va_list args, params_t params)
{
	specifier_field_t specifiers[] = {
		{"c", format_char},
		{"s", format_str},
		{"%", format_percent}i
		{NULL, NULL}
	};
	int i = 0;



