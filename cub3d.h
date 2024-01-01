/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:24:02 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/01 13:31:36 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define cellsize 64
# define fov 60
# define rayon 1000
# define BLACK100 0x000000FF
# define BLACK025 0x00000040 
# define WHITE100 0xFFFFFFFF
# define WHITE025 0xFFFFFF40
# define R100 0xFF0000FF
# define R025 0xFF000040
# define G025 0x00FF0040

typedef struct s_map
{
    char **map;
    int horizontale;
    int verticale;
}   t_map;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_player
{
    double angle;
    // double pdx;
    // double pdy;
    t_point position;
    t_point pixel_coord;
}   t_player;

typedef struct s_ray
{
    int x1;
    int y1;
    int x2;
    int y2;
    int dx;
    int dy;
    int dir_x;
    int dir_y;
    int dist_ray;
    int dist_player_screen;
}   t_ray;

typedef struct s_mlx
{
    mlx_t *id;
    mlx_image_t *img;
    mlx_image_t *img_ray;
    mlx_image_t *screen;
    t_player *player;
    t_map *cub;
    t_ray raycast;
    // int nb_rays;
    // int dist_player_screen;
    // int wall_height;
}   t_mlx;

//init

void init(t_map *cub,t_player *player);

//check

void check_args(char argc);
void	check_file_extension(char *file);
int	ft_open_fd(char *filename);

//map

char **read_map(char *file);
void check_map(char **map);
void find_pos(char **map,t_player *player);

//utils

void print_arr(char **arr);
void free_arr(char **map);
int count_line(char **map);
int absolute(int nb);

//mlx

void open_window(t_mlx *mlx);
void draw_cell(t_mlx *mlx,int x,int y);
void draw_cell_bis(t_mlx *mlx,int x,int y);
void draw_character(t_mlx *mlx);
void delete_character(t_mlx *mlx);

//event

void event(mlx_key_data_t event,void *content);
void loop(void *param);

//ray

int is_wall(t_mlx *mlx, int x, int y);
void draw_beam(t_mlx *mlx,int x1,int y1);
void delete_beam(t_mlx *mlx,int x1,int y1);

//moveset

void move_down(t_mlx *mlx);
void move_up(t_mlx *mlx);
void move_right(t_mlx *mlx);
void move_left(t_mlx *mlx);

//screen

void draw_screen(t_mlx *mlx);

//test


#endif