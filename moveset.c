/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:31:10 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/08 13:00:55 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_forward(t_mlx *mlx)
{
    if (mlx_is_key_down(mlx->id, MLX_KEY_W))
    {
        int distance = 5;
        int delta_x = distance * cos(mlx->player->angle);
        int delta_y = distance * sin(mlx->player->angle);

        int new_x = mlx->player->pixel_coord.x + delta_x;
        int new_y = mlx->player->pixel_coord.y + delta_y;
        if (!is_wall(mlx, new_x, new_y))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
            delete_screen(mlx);
            mlx->player->pixel_coord.x = new_x;
            mlx->player->pixel_coord.y = new_y;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
            draw_screen(mlx);
        }
    }
}

void move_backward(t_mlx *mlx)
{
    if (mlx_is_key_down(mlx->id, MLX_KEY_S))
    {
        int distance = 5;
        int delta_x = -distance * cos(mlx->player->angle);
        int delta_y = -distance * sin(mlx->player->angle);
        int new_x = mlx->player->pixel_coord.x + delta_x;
        int new_y = mlx->player->pixel_coord.y + delta_y;

        if (!is_wall(mlx, new_x, new_y))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
            delete_screen(mlx);
            mlx->player->pixel_coord.x = new_x;
            mlx->player->pixel_coord.y = new_y;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
            draw_screen(mlx);
        }
    }
}

void move_right(t_mlx *mlx)
{
    if (mlx_is_key_down(mlx->id, MLX_KEY_D))
    {
        int distance = 5;
        int delta_x = -distance * sin(mlx->player->angle);
        int delta_y = distance * cos(mlx->player->angle);
        int new_x = mlx->player->pixel_coord.x + delta_x;
        int new_y = mlx->player->pixel_coord.y + delta_y;

        if (!is_wall(mlx, new_x, new_y))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
            delete_screen(mlx);
            mlx->player->pixel_coord.x = new_x;
            mlx->player->pixel_coord.y = new_y;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
            draw_screen(mlx);
        }
    }
}

void move_left(t_mlx *mlx)
{
    if (mlx_is_key_down(mlx->id, MLX_KEY_A))
    {
        int distance = 5;
        int delta_x = distance * sin(mlx->player->angle);
        int delta_y = -distance * cos(mlx->player->angle);
        int new_x = mlx->player->pixel_coord.x + delta_x;
        int new_y = mlx->player->pixel_coord.y + delta_y;

        if (!is_wall(mlx, new_x, new_y))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
            delete_screen(mlx);
            mlx->player->pixel_coord.x = new_x;
            mlx->player->pixel_coord.y = new_y;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
            draw_screen(mlx);
        }
    }
}
