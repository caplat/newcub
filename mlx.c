/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:25:30 by derblang          #+#    #+#             */
/*   Updated: 2024/01/10 13:58:05 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void open_window(t_mlx *mlx)
{
    bool success;
    mlx->id = mlx_init(WIDTH,HEIGHT,"CUBE",true);
    if(!mlx->id)
        ft_puterror("problem with window");
    mlx->screen = mlx_new_image(mlx->id,WIDTH,HEIGHT);
    mlx->img = mlx_new_image(mlx->id,WIDTH, HEIGHT);
    mlx->img_ray = mlx_new_image(mlx->id,WIDTH,HEIGHT);
    mlx_image_to_window(mlx->id,mlx->screen,0,0);
    mlx_image_to_window(mlx->id,mlx->img,0,0);
    mlx_image_to_window(mlx->id,mlx->img_ray,0,0);
    load_img(mlx->cub);
    texture_to_image(mlx);
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
    while(i < cellsize)
    {
        while(j < cellsize)
        {
            mlx_put_pixel(mlx->img,x + j ,y + i, rgb_to_hex(0,40,0,255));
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
    while(i < cellsize)
    {
        while(j < cellsize)
        {
            mlx_put_pixel(mlx->img,(x + j) ,(y + i) , rgb_to_hex(128,128,128,255));
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

    x = -(cellsize / 8);
    y = -(cellsize / 8);
    while(x < (cellsize / 8))
    {
        while(y < (cellsize / 8))
        {
            mlx_put_pixel(mlx->img, (mlx->player->pixel_coord.x  + x ) ,(mlx->player->pixel_coord.y + y),rgb_to_hex(0, 0, 64, 255));
            y++;
        }
        x++;
        y = -(cellsize / 8);
    }
}

void delete_character(t_mlx *mlx)
{
    int x;
    int y;

    x = -(cellsize / 8);
    y = -(cellsize / 8);
    while(x < (cellsize / 8))
    {
        while(y < (cellsize / 8))
        {
            mlx_put_pixel(mlx->img, mlx->player->pixel_coord.x + x,mlx->player->pixel_coord.y + y, rgb_to_hex(0, 0, 0, 255));
            y++;
        }
        x++;
        y = -(cellsize / 8);
    }
}