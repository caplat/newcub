/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:47 by derblang          #+#    #+#             */
/*   Updated: 2024/01/09 14:09:20 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void load_img(t_cub *cub)
{
    cub->north_tex = mlx_load_png(cub->pathNorth);
    cub->south_tex = mlx_load_png(cub->pathSouth);
    cub->east_tex = mlx_load_png(cub->pathEast);
    cub->west_tex = mlx_load_png(cub->pathWest);
    if(!cub->north_tex || !cub->south_tex || !cub->east_tex || !cub->west_tex)
    {
        printf("Error loading images!\n");
        exit(1);
    }
}

int rgb_to_hex(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}


