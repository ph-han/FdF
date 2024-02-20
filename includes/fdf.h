/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:18:13 by phan              #+#    #+#             */
/*   Updated: 2023/07/10 12:32:49 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>

# define HEIGHT     1000
# define WIDTH      1600

# define ESC        53

# define LEFT       123
# define RIGHT      124
# define DOWN       125
# define UP         126

# define PLAN       35
# define ISOMETRIC  34

# define UPMOUSE    5
# define DOWNMOUSE  4

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}    t_img;

typedef struct s_point
{
    double  x;
    double  y;
    double  z;
    long    color;
}    t_point;

typedef struct s_angle
{
    double  alpha;
    double  beta;
    double  gamma;
}    t_angle;

typedef struct s_map
{
    int     width;
    int     height;
    int     move_x;
    int     move_y;
    int     is_axis_show;
    double  ratio;
    t_point axis[3];
    t_point original_axis[3];
    t_point *original_map;
    t_point *transformed_map;
}    t_map;

typedef struct s_fdf
{
    void    *mlx;
    void    *win;
    int     win_width;
    int     win_height;
    t_img   *img;
    t_map   *map;
    t_angle *angle;
}    t_fdf;

typedef struct s_line
{
    double  dx;
    double  dy;
    double  step;
    double  xinc;
    double  yinc;
    double  cinc;
}    t_line;

// init funcs
void            init_angle(t_angle *angle);
void            init_map(t_map *map);
void            init_fdf(t_fdf *fdf);
void            init_img(t_fdf *fdf);
void            init_mlx_window(t_fdf *fdf);

// utils
void            my_perror(char *err_msg);
void            mapcpy(t_point *src, t_point *obj, int size);
int             close_win(t_fdf *fdf);
int             fdf_atoi(char *str);

// check funcs
int             is_valid_filename(char *filename);
int             is_vaild_num(char *data);
int             is_valid_data(char *data);
long            check_and_set_color(char *color);

// parse utils funcs
void            free_split(char **split_line);
int             get_line_width(char *line);
int             fdf_strlen(char *s);
int             ft_find(char *hex, char c);

// parse funcs
void            parse_map(t_map *map, char *filename);

// projection funcs
void            to_isometric(t_fdf *fdf);
void            to_plan(t_fdf *fdf);

// rotate matrix funcs
void            rotate(t_point *point, double angle, t_point axis);
void            rotate_y(t_point *point, t_angle *angle);
void            rotate_z(t_point *point, t_angle *angle);

// rotate map
void            rotate_map_x(t_fdf *fdf, double r);
void            rotate_map_y(t_fdf *fdf, double r);
void            rotate_map_z(t_fdf *fdf, double r);
int             auto_rotate(t_fdf *fdf);

// move map
void            move_left(t_fdf *fdf);
void            move_right(t_fdf *fdf);
void            move_up(t_fdf *fdf);
void            move_down(t_fdf *fdf);

// zoom map
void            zoom_in(t_fdf *fdf);
void            zoom_out(t_fdf *fdf);

// line algo funcs
void            dda(t_img *data, t_map *map, t_point point1, t_point point2);

// map scaling funcs
void            scaling(t_map *map);

// draw map funcs
void            put_pixel(t_img *data, int x, int y, int color);
void            draw_map_column(t_img *img, t_map *map);
void            draw_map_row(t_img *img, t_map *map);
void            draw_map(t_fdf *fdf);

// color funcs
int             get_a(long color);
int             get_r(long color);
int             get_g(long color);
int             get_b(long color);
unsigned int    gradation(long color1, long color2, double cinc);

// hook
void            set_hooks(t_fdf *fdf);
int             mouse_hooks(int key_code, int x, int y, t_fdf *fdf);
int             key_hooks(int key_code, t_fdf *fdf);


// temp
void    draw_axis(t_fdf *fdf);
#endif
