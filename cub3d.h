/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:24:02 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/20 11:48:26 by acaplat          ###   ########.fr       */
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
    t_point position;
    t_point pixel_coord;
}   t_player;

typedef struct s_mlx
{
    mlx_t *id;
    mlx_image_t *img;
    t_player *player;
    t_map *cub;
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

//mlx

void open_window(t_mlx *mlx);
void draw_cell(t_mlx *mlx,int x,int y);
void draw_cell_bis(t_mlx *mlx,int x,int y);
void draw_character(t_mlx *mlx);
void delete_character(t_mlx *mlx);

//event

void event(mlx_key_data_t event,void *content);
void loop(void *param);

#endif