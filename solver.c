#include "fillit.h"

static	int	ft_sqrt(int qt_shapes)
{
	int sq;
	int perimeter;

	sq = 2;
	perimeter = qt_shapes * 4;
	while (sq * sq < perimeter)
		sq++;
	return (sq);
}

static int ft_shift(t_tetr *tetr, int x_shift, int y_shift)
{
	tetr->x_sh = x_shift;
	tetr->y_sh = y_shift;
	return (OK);
}

static int	ft_locate(t_tetr *tetr, uint16_t *map, int square)
{
	int x;
	int y;

	y = -1;
	if (!(tetr->t))
		return (OK);
	while (++y + tetr->h <= square)
	{
		x = -1;
		while (++x + tetr->w <= square)
		{
			if (!(tetr->t & *(uint64_t *)(map + y)))
			{
				*(uint64_t *)(map + y) ^= tetr->t;
				if ((ft_shift(tetr, x, y) == OK) && (ft_locate(tetr + 1, map, square) == OK))
					return (OK);
				*(uint64_t *)(map + y) ^= tetr->t;
			}
			tetr->t >>= 1;
		}
		tetr->t <<= x;
	}
	return (ERROR);
}

int		ft_solver(t_tetr *tetr, uint16_t *map, int qt)
{
	int sq;

	sq = ft_sqrt(qt);
	while (ft_locate(tetr, map, sq))
		sq++;
	return (sq);
}
