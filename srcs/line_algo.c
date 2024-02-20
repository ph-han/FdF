/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:12 by phan              #+#    #+#             */
/*   Updated: 2023/07/08 13:15:20 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width_center(t_map *map)
{
	const int   mid_x = map->width / 2;
	const int   mid_y = map->width * (map->height / 2);

    return ((WIDTH - (map->transformed_map[mid_x + mid_y].x)) / 2);
}

static int	get_height_center(t_map *map)
{
	const int   mid_x = map->width / 2;
	const int   mid_y = map->width * (map->height / 2);

	return ((HEIGHT - (map->transformed_map[mid_x + mid_y].y)) / 2);
}

void	dda(t_img *data, t_map *map, t_point point1, t_point point2)
{
	t_line	line_info;
	int		i = -1;
    int     is_dx_more_big;

	line_info.dx = point2.x - point1.x;
	line_info.dy = point2.y - point1.y;

    is_dx_more_big = fabs(line_info.dx) > fabs(line_info.dy);
    line_info.step = is_dx_more_big ? fabs(line_info.dx) : fabs(line_info.dy);

	line_info.xinc = line_info.dx / line_info.step;
	line_info.yinc = line_info.dy / line_info.step;

	while (++i <= line_info.step)
	{
        is_dx_more_big = fabs(point2.x - point1.x) > fabs(point2.y - point1.y);
        line_info.cinc = is_dx_more_big ? fabs(point2.x - point1.x) : fabs(point2.y - point1.y);
        line_info.cinc /= line_info.step;
        put_pixel(data, point1.x + get_width_center(map) + map->move_x, \
            point1.y + get_height_center(map) + map->move_y, \
            gradation(point1.color, point2.color, line_info.cinc));
		point1.x += line_info.xinc;
		point1.y += line_info.yinc;
	}
}
