#include "fillit.h"

int	ft_open(char *argv)
{
	int fd;

	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error();
	return (fd);
}
