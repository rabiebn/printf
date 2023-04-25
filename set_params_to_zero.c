#include "main.h"

/**
 *  * init_params - reset struct fields to zero
 *   * @args: arguments' pointer
 *    * @par: the parameters struct
 *     * 
 *     */
void set_params_to_zero(va_list args, params_t *par)
{
	par->unsign = 0;
	par->plus_flag = 0;
	par->space_flag = 0;
	par->hashtag_flag = 0;
	par->zero_flag = 0;
	par->minus_flag = 0;
	par->width = 0;
	par->percision = UINT_MAX;
	par->h_mod = 0;
	par->l_mod = 0;
	(void)args;
}
