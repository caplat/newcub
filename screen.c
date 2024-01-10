/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:58:01 by derblang          #+#    #+#             */
/*   Updated: 2024/01/10 17:35:08 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_screen(t_mlx *mlx)
{
    int x;
    int y;
    float wall_height;

    x = 0;
    y = 0;
    while(x < WIDTH)
    {
        wall_height = (HEIGHT * cellsize) / (mlx->tab[x]);
        while(y < HEIGHT)
        {
            if(y < (HEIGHT / 2) + (wall_height / 2))
                mlx_put_pixel(mlx->screen,x,y,rgb_to_hex(mlx->cub->ceilling[0], mlx->cub->ceilling[1], mlx->cub->ceilling[2], 255));
            if(y > (HEIGHT / 2) - (wall_height / 2))
                mlx_put_pixel(mlx->screen,x,y,rgb_to_hex(mlx->cub->floor[0], mlx->cub->floor[1], mlx->cub->floor[2], 255));
            if(y > (HEIGHT / 2) - (wall_height / 2) && y < (HEIGHT / 2) + (wall_height / 2))
            {
                if(mlx->tab_wall[x].orient == 'N')
                    mlx_put_pixel(mlx->screen,x,y,0x808080FF);
                else
                    mlx_put_pixel(mlx->screen,x,y,rgb_to_hex(1, 55, 150, 255));
                // mlx_image_to_window(mlx->id,mlx->cub->north_img,x,y);
            }
            y++;
        }
        x++;
        y = 0;
    }
}

void delete_screen(t_mlx *mlx)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(x < WIDTH)
    {
        while(y < HEIGHT)
        {
            mlx_put_pixel(mlx->screen,x,y,rgb_to_hex(0,0,0,255));
            y++;
        }
        x++;
        y = 0;
    }
}