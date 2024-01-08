/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:24:02 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/08 16:25:39 by acaplat          ###   ########.fr       */
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
# define cellsize 32
# define fov 60
# define rayon 1000
# define BLACK100 0x000000FF
# define BLACK050 0x000000870
# define BLACK025 0x00000040
# define WHITE100 0xFFFFFFFF
# define WHITE050 0xFFFFFF80
# define WHITE025 0xFFFFFF40
# define R100 0xFF0000FF
# define R050 0xFF000080
# define R025 0xFF000040
# define G025 0x00FF0040

typedef struct s_cub
{
    char **map;
    char *floor_color;
    char *ceilling_color;
    int horizontale;
    int verticale;  
    int floor[3];
    int ceilling[3];
    char *pathNorth;
    char *pathSouth;
    char *pathEast;
    char *pathWest;
    mlx_texture_t *north_tex;
    mlx_texture_t *south_tex;
    mlx_texture_t *east_tex;
    mlx_texture_t *west_tex;
    mlx_image_t *minimap;
    mlx_image_t *bigmap;
    mlx_image_t		*west_image;
	mlx_image_t		*east_image;
	mlx_image_t		*north_image;
	mlx_image_t		*south_image;
    
}   t_cub;

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
    // int dist_player_screen;
}   t_ray;

typedef struct s_mlx
{
    mlx_t *id;
    mlx_image_t *img;
    mlx_image_t *img_ray;
    mlx_image_t *screen;
    t_player *player;
    t_cub *cub;
    t_ray raycast;
    int *tab;
    // int nb_rays;
    // int dist_player_screen;
    // int wall_height;
}   t_mlx;

//init

void init(t_cub *cub,t_player *player);

//check

void check_args(char argc);
void	check_file_extension(char *file);
int	ft_open_fd(char *filename);
int	ft_strstr(char *str, char *to_find);

//map

char **read_map(char *file);
void check_map(char **map);
void find_pos(char **map,t_player *player);

//utils

void print_arr(char **arr);
void free_arr(char **map);
int count_line(char **map);
int absolute(int nb);
void print_nb_arr(int *tab);
void free_tab(int *tab,int count);
char ** map_cpy(char **map,int verticale);

//mlx

void open_window(t_mlx *mlx);
void draw_cell(t_mlx *mlx,int x,int y);
void draw_cell_bis(t_mlx *mlx,int x,int y);
void draw_character(t_mlx *mlx);
void delete_character(t_mlx *mlx);

//event

void draw_map(t_mlx *mlx);
void event(mlx_key_data_t event,void *content);
void loop(void *param);

//ray

int is_wall(t_mlx *mlx, int x, int y);
void draw_beam(t_mlx *mlx,int x1,int y1);
void delete_beam(t_mlx *mlx,int x1,int y1);

//moveset

void move_right(t_mlx *mlx);
void move_left(t_mlx *mlx);
void move_forward(t_mlx *mlx);
void move_backward(t_mlx *mlx);

//screen

void draw_screen(t_mlx *mlx);
void delete_screen(t_mlx *mlx);

//wall

void check_wall(char **map,t_cub *cub);

//flood_fill

void flood_fill(char **map,int horizontale,int verticale);
void fill_bis(char **map,t_point cur,t_cub *cub);


//damla

int check_map_components(char **map);
int invalid_char_check(char **map);
void check_all_map(char *file,t_cub *cub);
char	**get_map_description(char **map);
void texture_check(char *line, int *count);
void check_wall_damla(char **map);
char	**ft_arrdup(char **arr);

//test


#endif