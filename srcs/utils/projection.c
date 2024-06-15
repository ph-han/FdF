/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:13:02 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:50 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_plan(t_fdf *fdf)
{
	mapcpy(fdf->map->original_map, fdf->map->transformed_map,
		fdf->map->width * fdf->map->height);
	init_map(fdf->map);
	scaling(fdf->map);
	draw_map(fdf);
}

void	to_isometric(t_fdf *fdf)
{
	int     i = 0;
    double  prev_x = 0;
    double  prev_y = 0;
    double  prev_z = 0;
    t_angle angle;

    mapcpy(fdf->map->original_map, fdf->map->transformed_map, fdf->map->width * fdf->map->height);
    init_angle(fdf->angle);
    init_map(fdf->map);
    angle = *(fdf->angle);
	while (i < (fdf->map->height) * (fdf->map->width)) {
        prev_x = fdf->map->transformed_map[i].x;
        prev_y = fdf->map->transformed_map[i].y;
        prev_z = fdf->map->transformed_map[i].z;
        fdf->map->transformed_map[i].x = prev_x * cos(angle.gamma) + prev_y * sin(angle.gamma);
        fdf->map->transformed_map[i].y = cos(angle.alpha) * (prev_x * -sin(angle.gamma) + prev_y * cos(angle.gamma)) - sin(angle.alpha) * prev_z;
        fdf->map->transformed_map[i].z = sin(angle.alpha) * (prev_x * -sin(angle.gamma) + prev_y * cos(angle.gamma)) + cos(angle.alpha) * prev_z;
        i++;
    }
    for (int i = 0; i < 3; i++)
    {
        prev_x = fdf->map->axis[i].x;
        prev_y = fdf->map->axis[i].y;
        prev_z = fdf->map->axis[i].z;
        fdf->map->axis[i].x = prev_x * cos(angle.gamma) + prev_y * sin(angle.gamma);
        fdf->map->axis[i].y = cos(angle.alpha) * (prev_x * -sin(angle.gamma) + prev_y * cos(angle.gamma)) - sin(angle.alpha) * prev_z;
        fdf->map->axis[i].z = sin(angle.alpha) * (prev_x * -sin(angle.gamma) + prev_y * cos(angle.gamma)) + cos(angle.alpha) * prev_z;
    }
    scaling(fdf->map);
    draw_map(fdf);
    if (fdf->map->is_axis_show)
        draw_axis(fdf);
}

void to_sphere(t_fdf *fdf)
{
    // 구로 보이게 좌표이동 예정
}