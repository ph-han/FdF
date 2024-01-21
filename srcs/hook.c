//
// Created by 한필호 on 1/20/24.
//

#include "fdf.h"

void set_hooks(t_fdf *fdf)
{
    mlx_mouse_hook(fdf->win, mouse_hooks, fdf);
    mlx_hook(fdf->win, 2, 1L << 0, key_hooks, fdf);
    mlx_hook(fdf->win, 17, 1L << 5, close_win, fdf);
    mlx_loop(fdf->mlx);
}

int    mouse_hooks(int key_code, int x, int y, t_fdf *fdf)
{
    (void)x;
    (void)y;
    if (key_code == UPMOUSE)
        zoom_in(fdf);
    else if (key_code == DOWNMOUSE)
        zoom_out(fdf);
    return (0);
}

int    key_hooks(int key_code, t_fdf *fdf)
{
    if (key_code == ESC)
        close_win(fdf);
    if (key_code == 18)
        rotate_map_x(fdf, 0.05);
    else if (key_code == 19)
        rotate_map_x(fdf, -0.05);
    else if (key_code == 20)
        rotate_map_y(fdf, 0.05);
    else if (key_code == 21)
        rotate_map_y(fdf, -0.05);
    else if (key_code == 22)
        rotate_map_z(fdf, 0.05);
    else if (key_code == 23)
        rotate_map_z(fdf, -0.05);
    else if (key_code == LEFT)
        move_left(fdf);
    else if (key_code == RIGHT)
        move_right(fdf);
    else if (key_code == DOWN)
        move_down(fdf);
    else if (key_code == UP)
        move_up(fdf);
    else if (key_code == ISOMETRIC)
        to_isometric(fdf);
    else if (key_code == PLAN)
        to_plan(fdf);
    return (0);
}