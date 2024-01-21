/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:21:01 by phan              #+#    #+#             */
/*   Updated: 2023/07/10 12:22:09 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_coordinate(t_map *map, char **line_split, int x, int y)
{
	t_point	point;
	char	**data_split;
	int		data_wc;

	while (line_split[x])
	{
		data_split = ft_split(line_split[x], ',');
		data_wc = is_valid_data(line_split[x]);
		if (!is_vaild_num(data_split[0]))
			my_perror("Invalid map data!");
		if (data_wc == 2)
		{
			point.color = check_and_set_color(data_split[1]);
			if (point.color == -1)
				my_perror("Invalid color code!");
		}
		else
			point.color = 0x00FFFFFF;
		point.x = x;
		point.y = y;
		point.z = fdf_atoi(data_split[0]);
		map->original_map[x++ + map->width * y] = point;
		free_split(data_split);
	}
}

static void	set_map(int fd, t_map *map, int y)
{
	char	*line;
	char	**line_split;

	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		free(line);
		set_coordinate(map, line_split, 0, y++);
		free_split(line_split);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

static void	check_map_info(int fd, t_map *map)
{
	char	*line = NULL;
	char	**line_split = NULL;
    int     curr_width;

    line = get_next_line(fd);
    while (line && (*line == '\n' || *line == '\0'))
    {
        line_split = ft_split(line, ' ');
        free(line);
        if (!line_split || !*line_split)
            my_perror("Invalid map info!");
        line = get_next_line(fd);
    }
    if (line == NULL)
        my_perror("Empty File!");
	map->width = get_line_width(line);
	map->height = 0;
	while (line)
	{
        curr_width = get_line_width(line);
		if (curr_width != (int)(map->width))
			my_perror("Map size error!");
		map->height++;
		line = get_next_line(fd);
	}
    map->transformed_map = (t_point *)malloc(sizeof(t_point) * map->width * map->height);
    map->original_map = (t_point *)malloc(sizeof(t_point) * map->width * map->height);
    if (!(map->transformed_map) || !(map->original_map))
        my_perror("Malloc error!");
	free(line);
	close(fd);
}

void	parse_map(t_map *map, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		my_perror("file open error! check your input");
    check_map_info(fd, map);
	fd = open(filename, O_RDONLY);
    set_map(fd, map, 0);
}
