/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:23:31 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/08 12:12:06 by acaplat          ###   ########.fr       */
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
                mlx_put_pixel(mlx->screen,x,y,0xADD8E6FF);
            if(y > (HEIGHT / 2) - (wall_height / 2))
                mlx_put_pixel(mlx->screen,x,y,0x8088040);
            if(y > (HEIGHT / 2) - (wall_height / 2) && y < (HEIGHT / 2) + (wall_height / 2))
                mlx_put_pixel(mlx->screen,x,y,G025);
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
            mlx_put_pixel(mlx->screen,x,y,0x00000000);
            y++;
        }
        x++;
        y = 0;
    }
}