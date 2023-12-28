/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:18:50 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/28 22:19:45 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void draw_map(t_mlx *mlx)
{
    int x;
    int y;

    while(mlx->cub->map[y])
    {
        while(mlx->cub->map[y][x])
        {
            if(mlx->cub->map[y][x] == '1')
                draw_cell(mlx,x * cellsize,y * cellsize);
            if(mlx->cub->map[y][x] == '0' || mlx->cub->map[y][x] == 'N' || mlx->cub->map[y][x] == 'S' 
                || mlx->cub->map[y][x] == 'E' || mlx->cub->map[y][x] == 'W')
                draw_cell_bis(mlx,x * cellsize,y * cellsize);
            x++;
        }
        y++;
        x = 0;
    }
}

static void update_pos_player(t_mlx *mlx)
{
    draw_character(mlx);
    draw_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
    if(mlx_is_key_down(mlx->id, MLX_KEY_S))
    {
        delete_character(mlx);
        delete_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        mlx->player->pixel_coord.y += 5;
        draw_character(mlx);
        draw_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
    }
    if(mlx_is_key_down(mlx->id, MLX_KEY_W))
    {
        delete_character(mlx);
        delete_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        mlx->player->pixel_coord.y -= 5;
        draw_character(mlx);
        draw_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
    }
    if(mlx_is_key_down(mlx->id, MLX_KEY_D))
    {
        delete_character(mlx);
        delete_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        mlx->player->pixel_coord.x += 5;
        draw_character(mlx);
        draw_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
    }
    if(mlx_is_key_down(mlx->id, MLX_KEY_A))
    {
        delete_character(mlx);
        delete_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        mlx->player->pixel_coord.x -= 5;
        draw_character(mlx);
        draw_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
    }
}

static void rotate(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_LEFT))
    {
        delete_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        mlx->player->angle -= (5 * M_PI) / 180;
        if(mlx->player->angle > 2 * M_PI)
            mlx->player->angle -= 2 * M_PI;
    }
    if(mlx_is_key_down(mlx->id, MLX_KEY_RIGHT))
    {
        delete_line(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        mlx->player->angle += (5 * M_PI) / 180;
        if(mlx->player->angle < 0)
            mlx->player->angle += 2 * M_PI;
    }
    // mlx->player->pdx = cosf(mlx->player->angle);
    // mlx->player->pdy = sinf(mlx->player->angle);
}

void event(mlx_key_data_t event,void *content)
{
    t_mlx *mlx;

    (void)event;
    mlx = content;
    if(mlx_is_key_down(mlx->id, MLX_KEY_ESCAPE))
        mlx_close_window(mlx->id);
    rotate(mlx);
    // if(mlx_is_key_down(mlx->id, MLX_KEY_RIGHT))
    // {
    //     mlx->player->angle -= (5 * M_PI) / 180;
    //     if(mlx->player->angle < 0)
    //         mlx->player->angle += 2 * M_PI;
    // }
}

void loop(void *param)
{
    t_mlx *mlx;

    mlx = param;
    draw_map(mlx);
    update_pos_player(mlx);
}
