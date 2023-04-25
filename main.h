#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARAMS_ZER0 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


/**
 * struct parameters - our parameters structure
 * @insign: flag in insigned value
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if space_flag specified
 * @hashtag_flag: on if hashtag_flag specified
 * @zero_flag: on if zero_flag specified
 * @minus_flag: on if plus_flag specified
 * @width: field width specifier
 * @precision: field precision specifier
 * @h_modifier: on if specified
 * @l_modifier: on if specified
 */
typedef struct parameters
{
	unsigned int insign		:1;
	unsigned int plus_flag		:1;
	unsigned int space_flag		:1;
	unsigned int hashtag_flag	:1;
	unsigned int zero_flag          :1;
	unsigned int minus_flag         :1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier         :1;
	unsigned int l_modifier         :1;
} params_t;

/**
 * struct specifier - structure for specifier 
 * @specifier: the specifier
 * @f: the function to apply
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* parametres function*/
void init_params(params_t *params; va_list args);

/*write function*/



/* _printf prototype*/
int _printf(const char *format, ...);

/* print_format_functions*/
int format_char(va_list args, params_t *params);
int format_str(va_list args, params_t *params);
int format_percent(va_list args, params_t *params);

#endif /*end _MAIN_H_*/
