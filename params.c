#include "main.h"

/**
 * init_params - initialize all the struct's fields to their default values
 * @params: struct parameters
 * @args: the arguments
 * Return: void
 */
void init_params(params_t *params, va_list args)
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
