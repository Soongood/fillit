#include "fillit.h"

static void ft_corner(uint16_t *shape)
{
    while (!(*shape & 61440))
        *shape <<= 4;
    while (!(*shape & 34952))
        *shape <<= 1;
}

static void ft_coordinates(uint16_t shape, int *x, int *y)
{
    int qt;
    int x_line;
    int y_line;

    qt = 0;
    y_line = 0;
    ft_corner(&shape);
    while (qt < 4 && y_line <= 3)
    {
        x_line = 0;
        while (qt < 4 && x_line <= 3)
        {
            if (shape & 32768)
            {
                *x++ = x_line;
                *y++ = y_line;
                qt++;
            }
            shape <<= 1;
            x_line++;
        }
        y_line++;
    }
}

t_tetr ft_convert(uint16_t shape)
{
    t_tetr form;
    uint16_t mask;
    uint16_t tmp;

    tmp = shape;
    mask = 0b0000000000001111;
    ft_bzero(&form, sizeof(form));
    while (tmp)
    {
        form.t |= tmp & mask;
        form.t <<= tmp >> 4 ? 16 : 0;
        form.h++;
        tmp >>= 4;
    }
    if (!(form.w = ((form.h == 1 || form.h == 3 || form.h == 4)) ? 5 - form.h : 0))
        form.w = !(shape ^ SQ) ? 2 : 3;
    form.t <<= 16 - form.w;
    ft_coordinates(shape, form.x, form.y);
    return (form);
}
