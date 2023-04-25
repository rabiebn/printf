#include "main.h"

/**
 * init_params - initialize all the struct's fields to their default values
 * @params: struct parameters 
 * @args: the arguments
 */
void init_params(params_t *params; va_list args)
{
	params->insign = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->width = 0;
	params->precision = UNIT_MAX;
	params->h_modifier = 0;
	params->l_modifier = 0;
	(void) args;
}


        unsigned int plus_flag          :1;
        unsigned int space_flag         :1;
        unsigned int hashtag_flag       :1;
        unsigned int zero_flag          :1;
        unsigned int minus_flag         :1;

        unsigned int width;
        unsigned int precision;

        unsigned int h_modifier         :1;
        unsigned int l_modifier         :1;

