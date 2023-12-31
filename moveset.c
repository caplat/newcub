/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:31:10 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/31 09:07:11 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_down(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_S))
    {
        if(!is_wall(mlx,mlx->player->pixel_coord.x,mlx->player->pixel_coord.y + 5))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
            mlx->player->pixel_coord.y += 5;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        }
    }
}

void move_up(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_W))
    {
        if(!is_wall(mlx,mlx->player->pixel_coord.x,mlx->player->pixel_coord.y - 5))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
            mlx->player->pixel_coord.y -= 5;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        }
    }
}

void move_right(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_D))
    {
        if(!is_wall(mlx,mlx->player->pixel_coord.x + 5,mlx->player->pixel_coord.y))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
            mlx->player->pixel_coord.x += 5;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        }
    }
}

void move_left(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_A))
    {
        if(!is_wall(mlx,mlx->player->pixel_coord.x - 5,mlx->player->pixel_coord.y))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
            mlx->player->pixel_coord.x -= 5;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        }
    }
}