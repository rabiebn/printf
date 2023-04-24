#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>/* write */
#include <stdarg.h>/* va_list, va_arg, va_start, va_end*/
#include <stdlib.h>/* malloc, free*/

/* tool functions */
int _strlen(char *s);
void _strcpy(char *dest, char *src);

/* printf functions */
int _printf(const char *format, ...);
int * (*get_func(char c))(va_list);
char *format_char(va_list args);
char *format_str(va_list args);

/**
 * * struct formats - struct
 * * @identifier: the identifier of type to print
 * * @f: function associated with format
 * */
typedef struct formats
{
	char identifier;
	char* (*func)(va_list);
}printf_t;

#endif
