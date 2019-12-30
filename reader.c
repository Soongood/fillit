#include "fillit.h"

t_tetr	ft_reader(char *argv, int file_d)
{
	t_tetr tetra;
	uint16_t tetramino;
	static int bytes = 0;
	static char buffer[547];
    static char *ptr = buffer;

	if (!bytes)
	{
		if ((bytes = read(file_d, buffer, 547)) < 0)
			ft_erorr(close(file_d));
		if ((bytes % 21) < 20)
			ft_erorr(close(file_d));
		buffer[bytes] = '\0';
		close(file_d);
	}
	if (bytes < 0)
	{
		ft_bzero(&tetra, sizeof(tetra));
		return (tetra);
	}
    if ((tetramino = ft_check_symbols(ptr, bytes > 21 ? 21 : 20)) == ERORR)
		ft_erorr();
	bytes -= 21;
	ptr += 21;
    return (tetra = ft_convert(tetramino));
}
