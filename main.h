#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

#define PARAMS_ZERO {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - struct of parameters
 * @unsign: flag for unsigned value
 * @plus_flag: plus_flag on when specified
 * @space_flag: space_flag on when specified
 * @hashtag_flag: hashtag_flag on when specified
 * @zero_flag: zero_flag on when specified
 * @minus_flag: minus_flag on when specified
 * @width: field width
 * @percision: field percision
 * @h_mod: on when specified
 * @l_mod: on when specified
 */
typedef struct parameters
{
	unsigned int unsign         : 1;

	unsigned int plus_flag      : 1;
	unsigned int space_flag     : 1;
	unsigned int hashtag_flag   : 1;
	unsigned int zero_flag      : 1;
	unsigned int minus_flag     : 1;

	unsigned int width;
	unsigned int percision;

	unsigned int h_mod          : 1;
	unsigned int l_mod          : 1;
} params_t;

/* set_params_to_zero.c */
void set_params_to_zero(params_t *par, va_list args);

/**
 * struct formats - struct
 * @identifier: the identifier of type to print
 * @func: function associated with format
 */
typedef struct formats
{
	char *identifier;
	int (*func)(va_list, params_t);
} printf_t;

/* put.c */
int _putchar(char c);
int _putstr(char *s);

/* format_funcs.c */
int _strlen(const char *s);
int _isdigit(int c);
int format_char(va_list args, params_t par);
int format_str(va_list args, params_t par);
int format_percent(va_list args, params_t par);

/* specifier.c */
int (*get_specifier(char *s))(va_list, params_t);
int get_func(char *s, va_list args, params_t par);
int get_flag(char *s, params_t par);
int get_modifier(char *s, params_t par);
char *get_width(char *s, params_t par, va_list args);
char *get_percision(char *s, params_t par, va_list args);

/* numbers.c*/
char *convert(long int num, int base, int flags, params_t par);
int print_unsigned(va_list args, params_t par);
int print_address(va_list args, params_t par);

/* convert_num.c */
int print_int(va_list args, params_t par);
int print_hex(va_list args, params_t par);
int print_HEX(va_list args, params_t par);
int print_binary(va_list args, params_t par);
int print_octal(va_list args, params_t par);

/* print_num.c */
int print_number(char *s, params_t par);
int print_number_right_shift(char *s, params_t par);
int print_number_left_shift(char *s, params_t par);
int print_S(va_list args, params_t par);

/* print_from_to.c */
int print_from_to(char *s, char *stop, char *except);
int print_rev(va_list args, params_t par);
int print_rot13(va_list args, params_t par);

/* _printf.c */
int _printf(const char *format, ...);

#endif
