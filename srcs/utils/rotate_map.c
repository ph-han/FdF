/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:05:18 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:54 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

void	rotate_map_x(t_fdf *fdf, double r)
{
	int	i = -1;

	while (++i < (fdf->map->height) * (fdf->map->width))
		rotate(fdf->map->transformed_map + i, r, fdf->map->axis[0]);
    rotate(&(fdf->map->axis[1]), r, fdf->map->axis[0]);
    rotate(&(fdf->map->axis[2]), r, fdf->map->axis[0]);
    draw_axis(fdf);
	draw_map(fdf);
}

void	rotate_map_y(t_fdf *fdf, double r)
{
    int	i = -1;

    while (++i < (fdf->map->height) * (fdf->map->width))
        rotate(fdf->map->transformed_map + i, r, fdf->map->axis[1]);
    rotate(&(fdf->map->axis[0]), r, fdf->map->axis[1]);
    rotate(&(fdf->map->axis[2]), r, fdf->map->axis[1]);
    draw_axis(fdf);
    draw_map(fdf);
}

void	rotate_map_z(t_fdf *fdf, double r)
{
    int	i = -1;

    while (++i < (fdf->map->height) * (fdf->map->width))
        rotate(fdf->map->transformed_map + i, r, fdf->map->axis[2]);
    rotate(&(fdf->map->axis[0]), r, fdf->map->axis[2]);
    rotate(&(fdf->map->axis[1]), r, fdf->map->axis[2]);
    draw_axis(fdf);
    draw_map(fdf);
}

