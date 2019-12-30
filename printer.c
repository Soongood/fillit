#include "fillit.h"

void ft_printer(t_tetr *tetr, int sq)
{
	int i;
	int j;
	int len;
	char *string;

	i = -1;
	len = sq * sq + sq;
	if (!(string = ft_strnew(len)))
		ft_erorr();
	ft_memset(string, '.', len);
	while (tetr[++i].t)
	{
		j = 0;
		while (j < 4)
			string[(tetr[i].y[j] + tetr[i].y_sh) * (sq + 1) + (tetr[i].x[j++] + tetr[i].x_sh)] = 'A' + i;
	}
	j = sq + 1;
	while (--j > 0)
		string[j * (sq + 1) - 1] = '\n';
	ft_putstr(string);
	free(string);
}
