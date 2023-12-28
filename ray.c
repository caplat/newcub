/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:14:55 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/28 23:55:47 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int is_wall(t_mlx *mlx, int x, int y)
{
    int map_x = floor(x / cellsize);
    int map_y = floor(y / cellsize);

    if (map_x >= 0 && map_x < WIDTH && map_y >= 0 && map_y < HEIGHT)
        return (mlx->cub->map[map_y][map_x] == '1');
    return 1;
}

void draw_line(t_mlx *mlx, int x1, int y1)
{
    int x2 = x1 + rayon * cosf(mlx->player->angle);
    int y2 = y1 + rayon * sinf(mlx->player->angle);
    int dx = absolute(x2 - x1);
    int dy = absolute(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int e2 = 2 * err;

    while(1)
    {
        mlx_put_pixel(mlx->img_ray, x1, y1, 0xFF0000FF);
        if((x1 == x2 && y1 == y2) || is_wall(mlx,x1,y1))
            break;
        e2 = 2 * err;
        if(e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if(e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void delete_line(t_mlx *mlx, int x1, int y1)
{
    int x2 = x1 + rayon * cosf(mlx->player->angle);
    int y2 = y1 + rayon * sinf(mlx->player->angle);
    int dx = absolute(x2 - x1);
    int dy = absolute(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int e2 = 2 * err;

    while(1)
    {
        mlx_put_pixel(mlx->img_ray, x1, y1, 0x00000000);
         if((x1 == x2 && y1 == y2) || is_wall(mlx,x1,y1))
            break;
        e2 = 2 * err;
        if(e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if(e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

// static void init_bis(t_mlx *mlx,int x1,int y1)
// {
//     mlx->raycast.x2 = x1 + rayon * cosf(mlx->player->angle);
//     mlx->raycast.y2 = y1 + rayon * sinf(mlx->player->angle);
//     mlx->raycast.dx = absolute(mlx->raycast.x2 - x1);
//     mlx->raycast.dy = absolute(mlx->raycast.y2 - y1);
//     mlx->raycast.dir_x = (x1 < mlx->raycast.x2) ? 1 : -1;
//     mlx->raycast.dir_y = (y1 < mlx->raycast.y2) ? 1 : -1;
// }

// void draw_line(t_mlx *mlx, int x1, int y1)
// {
//     int err = mlx->raycast.dx - mlx->raycast.dy;
//     int e2 = 2 * err;
//     init_bis(mlx,x1,y1);
//     while(1)
//     {
//         mlx_put_pixel(mlx->img_ray, x1, y1, 0xFF0000FF);
//         if((x1 == mlx->raycast.x2 && y1 == mlx->raycast.y2) || is_wall(mlx,x1,y1))
//             break;
//         e2 = 2 * err;
//         if(e2 > -mlx->raycast.dy)
//         {
//             err -= mlx->raycast.dy;
//             x1 += mlx->raycast.dir_x;
//         }
//         if(e2 < mlx->raycast.dx)
//         {
//             err += mlx->raycast.dx;
//             y1 += mlx->raycast.dir_y;
//         }
//     }
// }

// void delete_line(t_mlx *mlx, int x1, int y1)
// {
//     int err = mlx->raycast.dx - mlx->raycast.dy;
//     int e2 = 2 * err;
//     init_bis(mlx,x1,y1);
//     while(1)
//     {
//         mlx_put_pixel(mlx->img_ray, x1, y1, 0xFF000000);
//         if((x1 == mlx->raycast.x2 && y1 == mlx->raycast.y2) || is_wall(mlx,x1,y1))
//             break;
//         e2 = 2 * err;
//         if(e2 > -mlx->raycast.dy)
//         {
//             err -= mlx->raycast.dy;
//             x1 += mlx->raycast.dir_x;
//         }
//         if(e2 < mlx->raycast.dx)
//         {
//             err += mlx->raycast.dx;
//             y1 += mlx->raycast.dir_y;
//         }
//     }
// }
