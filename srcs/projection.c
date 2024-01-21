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
	int	i = 0;

    mapcpy(fdf->map->original_map, fdf->map->transformed_map, fdf->map->width * fdf->map->height);
    init_angle(fdf->angle);
    printf("alpha: %lf, beta: %lf, gamma: %lf\n", fdf->angle->alpha, fdf->angle->beta, fdf->angle->gamma);
	while (i < (fdf->map->height) * (fdf->map->width)) {
        rotate_z(fdf->map->transformed_map + i, fdf->angle);
        rotate_x(fdf->map->transformed_map + i, fdf->angle);
        i++;
    }
	init_map(fdf->map);
    scaling(fdf->map);
    draw_map(fdf);
}
