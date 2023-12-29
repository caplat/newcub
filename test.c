/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:44:02 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/29 16:41:29 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void test_init_ray(t_ray *ray, t_mlx *mlx, int x1, int y1,double angle)
{   
    (void)mlx;
    ray->x1 = x1;
    ray->y1 = y1;
    ray->x2 = x1 + rayon * cos(angle);
    ray->y2 = y1 + rayon * sin(angle);
    ray->dx = absolute(ray->x2 - x1);
    ray->dy = absolute(ray->y2 - y1);
    ray->dir_x = (x1 < ray->x2) ? 1 : -1;
    ray->dir_y = (y1 < ray->y2) ? 1 : -1;
}

void test_draw_line(t_mlx *mlx, int x1, int y1,double angle)
{
    t_ray *ray = &(mlx->raycast);
    int err;
    int e2;

    test_init_ray(ray,mlx,x1,y1,angle);
    err = ray->dx - ray->dy;
    e2 = 2 * err;
    while(1)
    {
        mlx_put_pixel(mlx->img_ray, x1, y1, 0xFF0000FF);
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

void test_draw_beam(t_mlx *mlx,int x1,int y1)
{
    int offset;
    double angle;

    offset = -30;
    while(offset < 30)
    {
        angle = mlx->player->angle + offset * (M_PI / 180);
        test_draw_line(mlx,x1,y1,angle);
        offset++;
    }
}