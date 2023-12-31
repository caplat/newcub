/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:14:55 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/31 12:12:53 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int is_wall(t_mlx *mlx, int x, int y)
{
    int map_x = floor(x / cellsize);
    int map_y = floor(y / cellsize);

    if (map_x >= 0 && map_x < WIDTH && map_y >= 0 && map_y < HEIGHT)
        return (mlx->cub->map[map_y][map_x] == '1');
    return 1;
}

static void init_ray(t_ray *ray, int x1, int y1,double angle)
{   
    ray->x1 = x1;
    ray->y1 = y1;
    ray->x2 = x1 + rayon * cos(angle);
    ray->y2 = y1 + rayon * sin(angle);
    ray->dx = absolute(ray->x2 - x1);
    ray->dy = absolute(ray->y2 - y1);
    ray->dir_x = (x1 < ray->x2) ? 1 : -1;
    ray->dir_y = (y1 < ray->y2) ? 1 : -1;
    ray->dist_ray = 0;
}

static void draw_line(t_mlx *mlx, int x1, int y1, double angle)
{
    t_ray *ray = &(mlx->raycast);
    int err;
    int e2;

    init_ray(ray,x1,y1,angle);
    err = ray->dx - ray->dy;
    e2 = 2 * err;
    while(1)
    {
        mlx_put_pixel(mlx->img_ray, x1, y1, R025);
        ray->dist_ray += sqrt(pow(ray->dir_x,2) + pow(ray->dir_y,2));
        if((x1 == ray->x2 && y1 == ray->y2) || is_wall(mlx,x1,y1))
            break;
        e2 = 2 * err;
        if(e2 > -ray->dy)
        {
            err -= ray->dy;
            x1 += ray->dir_x;
        }
        if(e2 < ray->dx)
        {
            err += ray->dx;
            y1 += ray->dir_y;
        }
    }
    mlx->wall_height = (mlx->dist_player_screen / ray->dist_ray) * HEIGHT;
}

static void delete_line(t_mlx *mlx, int x1, int y1,double angle)
{
    t_ray *ray = &(mlx->raycast);
    int err;
    int e2;

    init_ray(ray,x1,y1,angle);
    err = ray->dx - ray->dy;
    e2 = 2 * err;
    while(1)
    {
        mlx_put_pixel(mlx->img_ray, x1, y1, 0x00000000);
        if((x1 == ray->x2 && y1 == ray->y2) || is_wall(mlx,x1,y1))
            break;
        e2 = 2 * err;
        if(e2 > -ray->dy)
        {
            err -= ray->dy;
            x1 += ray->dir_x;
        }
        if(e2 < ray->dx)
        {
            err += ray->dx;
            y1 += ray->dir_y;
        }
    }
}

void draw_beam(t_mlx *mlx,int x1,int y1)
{
    int offset;
    double angle;

    offset = -3;
    mlx->nb_rays = -2 * offset;
    mlx->dist_player_screen = (WIDTH / 2) / (tan(-offset));
    while(offset < 3)
    {
        angle = mlx->player->angle + offset * (M_PI / 180);
        draw_line(mlx,x1,y1,angle);
        offset++;
    }
}

void delete_beam(t_mlx *mlx,int x1,int y1)
{
    int offset;
    double angle;

    offset = -3;
    while(offset < 3)
    {
        angle = mlx->player->angle + offset * (M_PI / 180);
        delete_line(mlx,x1,y1,angle);
        offset++;
    }
}
