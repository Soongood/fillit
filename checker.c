#include "fillit.h"

static uint16_t ft_check_shape(uint16_t *shape)
{
    int i;

    i = 0;
    while (!(*shape & HOR) || !(*shape & VER))
        *shape >>= !(*shape & HOR) ? 4 : 1;
	return ((!(*shape ^ HOR) || !(*shape ^ VER) || !(*shape ^ SQ) 
    || !(*shape ^ T) || !(*shape ^ PIN) || !(*shape ^ PIN_R) 
    || !(*shape ^ PIN_L) || !(*shape ^ L_G) || !(*shape ^ G) 
    || !(*shape ^ H_STICK) || !(*shape ^ R_STICK) || !(*shape ^ J)
    || !(*shape ^ ROOT) || !(*shape ^ R_ROOT) || !(*shape ^ L)
    || !(*shape ^ R_ZZ) || !(*shape ^ V_ZZ) || !(*shape ^ L_ZZ) || !(*shape ^ VR_ZZ)) ? *shape : ERORR);
}

uint16_t	ft_check_symbols(char *str, int length)
{
	int i;
	uint16_t shape;

	i = 0;
	shape = 0;
	while (i < length)
	{
	    if (str[i] != '#' && str[i] != '.' || (str[i] == '#' || str[i] == '.') && (!((i + 1) % 5) || !((i + 1) % 21)))
		{
			if ((!((i + 1) % 5) || !((i + 1) % 21)) && str[i++] == '\n')
			    continue;
			return (ERORR);
		}
		shape <<= 1;
		if (str[i++] == '#')
			shape |= 0b0000000000000001;
    }
	if (!shape)
		ft_erorr(); 
	return (ft_check_shape(&shape));
}
