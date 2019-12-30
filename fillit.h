#ifndef FILLIT_H
# define FILLIT_H

# define ERORR 1
# define OK 0

# define HOR 0b0000000000001111
# define VER 0b0001000100010001
# define SQ 0b0000000000110011
# define T 0b0000000001110010
# define PIN 0b0000000000100111
# define PIN_R 0b0000000100110001
# define PIN_L 0b0000001000110010
# define G 0b0000001100100010
# define L_G 0b0000001100010001
# define H_STICK 0b0000000001110001
# define R_STICK 0b0000000001110100
# define J 0b0000000100010011
# define ROOT 0b0000000000010111
# define R_ROOT 0b0000000001000111
# define L 0b0000001000100011
# define R_ZZ 0b0000000001100011
# define V_ZZ 0b0000000100110010
# define L_ZZ 0b0000000000110110
# define VR_ZZ 0b0000001000110001

#include "libft.h"
#include <fcntl.h>
#include <stdint.h>

typedef struct s_tetr
{
    uint64_t t;
    int x_sh;
    int y_sh;
    int h;
    int w;
    int x[4];
    int y[4];
} t_tetr;


void		ft_erorr();
void		ft_printer(t_tetr *tetr, int sq);
int		ft_open(char *argv);
int		ft_solver(t_tetr *tetr, uint16_t *map, int qt);
t_tetr		ft_convert(uint16_t shape);
t_tetr		ft_reader(char *argv, int file_d);
uint16_t	ft_check_symbols(char *str, int length);

#endif
