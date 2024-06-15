/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:12:45 by phan              #+#    #+#             */
/*   Updated: 2023/07/10 12:43:27 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_width(char *line)
{
	char	**line_split;
	int		width;

	width = 0;
	line_split = ft_split(line, ' ');
	while (line_split[width] && *line_split[width] != '\n')
        if (is_valid_data(line_split[width++]) == 0)
            my_perror("Invalid map data!");
	free_split(line_split);
	return (width);
}

int	ft_find(char *hex, char c)
{
	int	idx;

	idx = 0;
	while (hex[idx])
	{
		if (hex[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	fdf_strlen(char *s)
{
	int	len;

	len = 0;
	while (*(s + len) && *(s + len) != '\n')
		len++;
	return (len);
}
