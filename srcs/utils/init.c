/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:10:04 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:23 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	fdf->img = (t_img *)malloc(sizeof(t_img));
	fdf->angle = (t_angle *)malloc(sizeof(t_angle));
    fdf->mlx = mlx_init();
    if (fdf->mlx == NULL)
        my_perror("MLX error!");
    fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
    init_img(fdf);
}

void	init_img(t_fdf *fdf)
{
	fdf->img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, \
		&fdf->img->bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
}

void	init_angle(t_angle *angle)
{
	angle->alpha = M_PI / 3;
	angle->beta = M_PI / 6;
	angle->gamma = M_PI / 4;
}

void	init_map(t_map *map)
{
	map->ratio = HEIGHT / (double)map->height * 0.4;
	map->move_x = 0;
	map->move_y = 0;
    map->is_axis_show = 1;
    map->original_axis[0].x = -1;
    map->original_axis[0].y = 0;
    map->original_axis[0].z = 0;
    map->original_axis[0].color = 0x00ff0000;
    map->original_axis[1].x = 0;
    map->original_axis[1].y = 1;
    map->original_axis[1].z = 0;
    map->original_axis[1].color = 0x0000ff00;
    map->original_axis[2].x = 0;
    map->original_axis[2].y = 0;
    map->original_axis[2].z = 1;
    map->original_axis[2].color = 0x000000ff;
    for (int i = 0; i < 3; i++)
    {
        map->axis[i].x = map->original_axis[i].x;
        map->axis[i].y = map->original_axis[i].y;
        map->axis[i].z = map->original_axis[i].z;
        map->axis[i].color = map->original_axis[i].color;
    }
}

