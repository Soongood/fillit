#include "fillit.h"

int main (int argc, char **argv)
{
	uint16_t map[16];
	int i;
	t_tetr array[27];

	if (argc != 2)
		ft_putstr("usage ./fillit source_file\n");
	i = 0;
	ft_bzero(map, sizeof(map));
	ft_bzero(array, sizeof(array));
	while (i < 26)
	{
		array[i] = ft_reader(ft_open(argv[1]));
		if (!(array[i].t))
			break;
		i++;
	}
	ft_printer(array, ft_solver(array, map, i));
	return (0);
}
