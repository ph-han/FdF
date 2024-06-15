/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:00:00 by phan              #+#    #+#             */
/*   Updated: 2023/07/10 13:09:06 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_perror(char *err_msg)
{
	ft_putendl_fd(err_msg, 2);
	exit(1);
}

int	fdf_atoi(char *str)
{
	int		sign = 1;
	long	result = 0;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign * result) > 10000000 || (sign * result) < -10000000)
			my_perror("Data is over 10000000 or -10000000");
		str++;
	}
	return ((int)(sign * result));
}

void	mapcpy(t_point *src, t_point *obj, int size)
{
	int	i = -1;

	while (++i < size)
        obj[i] = src[i];
}

int	close_win(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
	return (0);
}

void	free_split(char **split_line)
{
	int	idx;

	idx = 0;
	while (split_line[idx])
		free(split_line[idx++]);
	free(split_line);
}
