/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:14:55 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/28 18:07:07 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static int is_wall(t_mlx *mlx, int x1,int y1,int sx, int sy)
// {
//     (void)mlx;
//     (void)y1;
//     (void)sx;
//     (void)sy;

//     // if(x1 % cellsize == 0)
//     // {
//     //     //  if(sy > 0 && mlx->cub->map[y1 / cellsize + 1][x1 / cellsize] == '1')
//     //     //     return(1);
//     //     if(sx > 0 && mlx->cub->map[y1 / cellsize][x1 / cellsize + 1] == '1')
//     //         return(1);
//     // }
//     if(y1 % cellsize == 0)
//     {
//         if(sy > 0 && mlx->cub->map[y1 / cellsize + 1][x1 / cellsize] == '1')
//             return(1);
//     }
//     return(0);
// }


static int is_wall(t_mlx *mlx, int x, int y)
{
    int cell_size = 64; // Taille de la cellule (ajustez si nécessaire)
    int map_x = floor(x / cell_size);
    int map_y = floor(y / cell_size);

    // Vérifier si la position (x, y) est dans les limites de la carte
    if (map_x >= 0 && map_x < WIDTH && map_y >= 0 && map_y < HEIGHT)
    {
        // Vérifier si la case correspondante dans la carte est un mur ('1')
        return (mlx->cub->map[map_y][map_x] == '1');
    }

    // En dehors des limites de la carte, traiter comme mur (ajustez selon vos besoins)
    return 1;
}


void draw_line(t_mlx *mlx, int x1, int y1)
{
    int x2 = 500;
    int y2 = 500;
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
    int x2 = 500;
    int y2 = 500;
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
