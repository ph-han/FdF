/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:39:10 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:16 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_over_window(int x, int y)
{
    return (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

    if (is_over_window(x, y) == 1)
        return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map_column(t_img *img, t_map *map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	j = 0;
	while (j < map->width)
	{
		i = 0;
		while (i < map->height - 1)
		{
			p1 = map->transformed_map[j + map->width * i];
			p2 = map->transformed_map[j + map->width * (i + 1)];
			dda(img, map, p1, p2);
			i++;
		}
		j++;
	}
}

void	draw_map_row(t_img *img, t_map *map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width - 1)
		{
			p1 = map->transformed_map[i + map->width * j];
			p2 = map->transformed_map[i + 1 + map->width * j];
			dda(img, map, p1, p2);
			i++;
		}
		j++;
	}
}

void    draw_axis(t_fdf *fdf)
{
    t_point origin;
    t_point tmp_axis;

    origin.x = 0;
    origin.y = 0;
    origin.z = 0;
    origin.color = 0x00ffffff;

    for (int i = 0; i < 3; i++)
    {
        tmp_axis.x = fdf->map->axis[i].x * 700;
        tmp_axis.y = fdf->map->axis[i].y * 700;
        tmp_axis.z = fdf->map->axis[i].z * 700;
        tmp_axis.color = fdf->map->axis[i].color;
        dda(fdf->img, fdf->map, origin, tmp_axis);
    }
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

void	draw_map(t_fdf *fdf)
{
    ft_memset(fdf->img->addr, 0, WIDTH * HEIGHT * (fdf->img->bits_per_pixel / 8));
	draw_map_column(fdf->img, fdf->map);
	draw_map_row(fdf->img, fdf->map);
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}
