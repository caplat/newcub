/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:47 by derblang          #+#    #+#             */
/*   Updated: 2024/01/10 13:57:02 by acaplat          ###   ########.fr       */
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
        printf("Error loading textures!\n");
        exit(1);
    }
}

int rgb_to_hex(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void texture_to_image(t_mlx *mlx)
{
    mlx->cub->north_img = mlx_texture_to_image(mlx->id,mlx->cub->north_tex);
    mlx->cub->south_img = mlx_texture_to_image(mlx->id,mlx->cub->south_tex);
    mlx->cub->east_img = mlx_texture_to_image(mlx->id,mlx->cub->east_tex);
    mlx->cub->west_img = mlx_texture_to_image(mlx->id,mlx->cub->west_tex);
    if(!mlx->cub->north_img || !mlx->cub->south_img || !mlx->cub->east_img || !mlx->cub->west_img)
    {
        printf("Error loading images!\n");
        exit(1);
    }
}

// void image_to_window(t_mlx *mlx)
// {
//     mlx_image_to_window(mlx->id,mlx->cub->north_img, x * cellsize,y * cellsize);
// }