/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:19:00 by phan              #+#    #+#             */
/*   Updated: 2024/05/17 18:19:33 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct s_point
{
	double x;
	double y;
	double z;
	long color;
} t_point;

typedef struct s_angle
{
	double alpha;
	double beta;
	double gamma;
} t_angle;

typedef struct s_map
{
	int width;
	int height;
	int move_x;
	int move_y;
	int is_axis_show;
	double ratio;
	t_point axis[3];
	t_point original_axis[3];
	t_point *original_map;
	t_point *transformed_map;
} t_map;

typedef struct s_fdf
{
	void *mlx;
	void *win;
	int win_width;
	int win_height;
	t_img *img;
	t_map *map;
	t_angle *angle;
} t_fdf;

typedef struct s_line
{
	double dx;
	double dy;
	double step;
	double xinc;
	double yinc;
	double cinc;
} t_line;

#endif