/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2024/01/10 16:28:40 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft/libft.h"
#include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define M_PI 3.14159265358979323846
# define cellsize 16
# define fov 60
# define rayon 1000
# define BLACK100 0x000000FF
# define BLACK025 0x00000040 
# define WHITE100 0xFFFFFFFF
# define WHITE025 0xFFFFFF40
# define R100 0xFF0000FF
# define R025 0xFF000040
# define G025 0x00FF0040
# define T00 0x00FFFFFF

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
    mlx_image_t *north_img;
    mlx_image_t *south_img;
    mlx_image_t *east_img;
    mlx_image_t *west_img;
} t_cub;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_orient
{
    int x;
    int y;
    char orient;
}   t_orient;

typedef struct s_float
{
    float x;
    float y;
} t_float;


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
    t_point wall_coord;
    t_orient *tab_wall;
}   t_mlx;

//init
void init(t_cub *cub, t_player *player);

//map
char **read_map(char *file);
void find_pos(char **map,t_player *player);
void check_all_map(char *file, t_cub *cub);


//flood fill

void flood_fill(char **map,int horizontale,int verticale);
void fill_bis(char **map,t_point cur,t_cub *cub);


//free
void free_cub(t_cub *cub);
void free_only_cub(t_cub *cub);

//check
int check_map_extension(char *str, t_cub *cub);
void check_args(char argc);
int	ft_open_fd(char *filename);
void	check_file_extension(char *file);


//check_map_utils
void texture_check(char *line, int *count);
char	**get_map_description(char **map);


//check_map
int invalid_char_check(char **map);
int check_map_components(char **map);

//wall
int	check_closed_around_space(char **map);
void check_wall(char **map);

//color 
void check_color_arr(char **arr);
void	convert_rgb(char *line, t_cub *cub, char c);
void get_color(char *line, t_cub *cub);
void check_color(t_cub *cub);
void parse_floor(t_cub *cub);
int color_range(t_cub *cub);


//mlx
void draw_cell_bis(t_mlx *mlx,int x,int y);
void draw_character(t_mlx *mlx);
void delete_character(t_mlx *mlx);
void draw_cell(t_mlx *mlx,int x,int y);
void open_window(t_mlx *mlx);


//event
void event(mlx_key_data_t keycode,void *content);
void loop(void *param);


//utils
void print_arr(char **arr);
int ft_arrlen(char **map);
void free_arr(char **map);
int count_line(char **map);
int absolute(int nb);

//texture
void check_map_texture(char **map, t_cub *cub);
void check_map_color(char **map, t_cub *cub);

//utils2
char ** map_cpy(char **map,int verticale);
char	**ft_arrdup(char **arr);
double abs_double(double nb);

//ray
void delete_beam(t_mlx *mlx,int x1,int y1);
void draw_beam(t_mlx *mlx,int x1,int y1);
int is_wall(t_mlx *mlx, int x, int y);
void find_wall_orientation(t_mlx *mlx,int x1,int y1);

//moveset
void move_left(t_mlx *mlx);
void move_forward(t_mlx *mlx);
void move_backward(t_mlx *mlx);
void move_right(t_mlx *mlx);

//screen

void draw_screen(t_mlx *mlx);
void delete_screen(t_mlx *mlx);

//load texture
void load_img(t_cub *cub);
int rgb_to_hex(int r, int g, int b, int a);
void texture_to_image(t_mlx *mlx);

#endif