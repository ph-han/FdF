/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_metrix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:23:11 by hanpilho          #+#    #+#             */
/*   Updated: 2023/07/07 12:25:56 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point    normalize(t_point axis)
{
    t_point normal_vec;
    int     vec_size = 0;

    vec_size = sqrt(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    normal_vec.x = axis.x / vec_size;
    normal_vec.y = axis.y / vec_size;
    normal_vec.z = axis.z / vec_size;

    return (normal_vec);
}

void	rotate(t_point *point, double angle, t_point axis)
{
    double  prev_point[3] = {point->x, point->y, point->z};
    double  new_point[3] = {0.0, 0.0, 0.0};
    t_point u = normalize(axis);

    double  rotate_metrix[3][3] =
        {
            {cos(angle) + pow(u.x, 2.0) * (1 - cos(angle)), u.x * u.y * (1 - cos(angle)) - u.z * sin(angle), u.x * u.z * (1 - cos(angle)) + u.y * sin(angle)},
            {u.x * u.y * (1 - cos(angle)) + u.z * sin(angle), cos(angle) + pow(u.y, 2.0) * (1 - cos(angle)), u.z * u.y * (1 - cos(angle)) - u.x * sin(angle)},
            {u.x * u.z * (1 - cos(angle)) - u.y * sin(angle), u.z * u.y * (1 - cos(angle)) + u.x * sin(angle), cos(angle) + pow(u.z, 2.0) * (1 - cos(angle))}
        };

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            new_point[i] += rotate_metrix[i][j] * prev_point[j];
    (point->x) = new_point[0];
	(point->y) = new_point[1];
	(point->z) = new_point[2];
}
