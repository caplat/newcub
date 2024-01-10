/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:14:09 by derblang          #+#    #+#             */
/*   Updated: 2024/01/10 17:26:40 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int is_wall(t_mlx *mlx, int x, int y)
{
    int map_x = floor(x / cellsize);
    int map_y = floor(y / cellsize);

    if (map_x >= 0 && map_x < WIDTH && map_y >= 0 && map_y < HEIGHT)
    {    
        if(mlx->cub->map[map_y][map_x] == '1')
        {
            mlx->wall_coord.x = x;
            mlx->wall_coord.y = y;
            return(1);
        }
    }
    return 0;
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
    // printf("%d\n",ray->dist_ray);
    // mlx->wall_height = (mlx->dist_player_screen / ray->dist_ray) * HEIGHT;
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
    double angle;
    int compteur;

    compteur = 0;
    angle = mlx->player->angle - ((fov / 2) * (M_PI / 180));
    while(angle <= mlx->player->angle + ((fov / 2) * (M_PI / 180)))
    {
        draw_line(mlx,x1,y1,angle);
        mlx->tab[compteur] = mlx->raycast.dist_ray * cosf(abs_double(mlx->player->angle - angle));
        mlx->tab_wall[compteur].x = mlx->wall_coord.x;
        mlx->tab_wall[compteur].y = mlx->wall_coord.y;
        compteur++;
        angle += (fov * (M_PI / 180)/ WIDTH);
    }
    find_wall_orientation(mlx,x1,y1);
}

void delete_beam(t_mlx *mlx,int x1,int y1)
{
    double angle;

    angle = mlx->player->angle - ((fov / 2) * (M_PI / 180));
    while(angle <= mlx->player->angle + ((fov / 2) * (M_PI / 180)))
    {
        delete_line(mlx,x1,y1,angle);
        angle += (fov * (M_PI / 180)/ WIDTH);
    }
}

void find_wall_orientation(t_mlx *mlx,int x1,int y1)
{
    int i;

    i = -1;
    while(mlx->tab_wall[++i].orient)
    {
        if(x1 > mlx->tab_wall[i].x && (abs(x1 - mlx->tab_wall[i].x) < abs(y1 - mlx->tab_wall[i].y)))   
           mlx->tab_wall[i].orient = 'W';
        else if(x1 < mlx->tab_wall[i].x && (abs(x1 - mlx->tab_wall[i].x) < abs(y1 - mlx->tab_wall[i].y)))   
           mlx->tab_wall[i].orient = 'E';
        else if(y1 < mlx->tab_wall[i].y && (abs(x1 - mlx->tab_wall[i].x) > abs(y1 - mlx->tab_wall[i].y)))
            mlx->tab_wall[i].orient = 'S';
        else if(y1 > mlx->tab_wall[i].y && (abs(x1 - mlx->tab_wall[i].x) > abs(y1 - mlx->tab_wall[i].y)))
            mlx->tab_wall[i].orient = 'N';   
    }

}