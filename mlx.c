/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:15:22 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/28 21:29:49 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void open_window(t_mlx *mlx)
{
    bool success;
    
    mlx->id = mlx_init(WIDTH,HEIGHT,"CUBE",true);
    if(!mlx->id)
        ft_puterror("problem with window");
    mlx->img = mlx_new_image(mlx->id,WIDTH,HEIGHT);
    mlx->img_ray = mlx_new_image(mlx->id,WIDTH,HEIGHT);
    mlx_image_to_window(mlx->id,mlx->img,0,0);
    mlx_image_to_window(mlx->id,mlx->img_ray,0,0);
    mlx_key_hook(mlx->id,event,mlx);
    success = mlx_loop_hook(mlx->id,loop,mlx);
    if(!success)
        ft_puterror("loop hook failed");
    mlx_loop(mlx->id);
    mlx_terminate(mlx->id);
}

void draw_cell(t_mlx *mlx,int x,int y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < cellsize - 1)
    {
        while(j < cellsize - 1)
        {
            mlx_put_pixel(mlx->img,x + j,y + i, 0x000000FF);
            j++;
        }
        i++;
        j = 0;
    }
}

void draw_cell_bis(t_mlx *mlx,int x,int y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < cellsize - 1)
    {
        while(j < cellsize - 1)
        {
            mlx_put_pixel(mlx->img,x + j,y + i, 0xFFFFFFFF);
            j++;
        }
        i++;
        j = 0;
    }
}
void draw_character(t_mlx *mlx)
{
    int x;
    int y;

    x = -8;
    y = -8;
    while(x < 8)
    {
        while(y < 8)
        {
            mlx_put_pixel(mlx->img, mlx->player->pixel_coord.x + x,mlx->player->pixel_coord.y + y,0xFF0000FF);
            y++;
        }
        x++;
        y = -8;
    }
}

void delete_character(t_mlx *mlx)
{
    int x;
    int y;

    x = -8;
    y = -8;
    while(x < 8)
    {
        while(y < 8)
        {
            mlx_put_pixel(mlx->img, mlx->player->pixel_coord.x + x,mlx->player->pixel_coord.y + y,0x00000000);
            y++;
        }
        x++;
        y = -8;
    }
}
