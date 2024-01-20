/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:35 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int    main(int ac, char *av[])
{
    t_fdf    fdf;

    if (ac != 2)
        ft_perror("Argument error!");

    if (!is_valid_filename(av[1]))
        ft_perror("Invalid filename!");

    init_fdf(&fdf);
    parse_map(fdf.map, av[1]);
    to_isometric(&fdf);
    set_hooks(&fdf);
    return (0);
}
