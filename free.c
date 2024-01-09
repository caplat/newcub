/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:41:24 by derblang          #+#    #+#             */
/*   Updated: 2023/12/18 13:05:56 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void free_texture(t_cub *cub)
{
    if(cub->south_tex)
        mlx_delete_texture(cub->south_tex);
    if(cub->north_tex)
        mlx_delete_texture(cub->north_tex);
    if(cub->east_tex)
        mlx_delete_texture(cub->east_tex);
    if(cub->west_tex)
        mlx_delete_texture(cub->west_tex);
}
void free_cub(t_cub *cub)
{
    if(cub->ceilling_color)
        free(cub->ceilling_color);
     if(cub->floor_color)
        free(cub->floor_color);
    if(cub->pathNorth)
        free(cub->pathNorth);
    if(cub->pathSouth)
        free(cub->pathSouth);
    if(cub->pathWest)
        free(cub->pathWest);
    if(cub->pathEast)
        free(cub->pathEast);
    if(cub->map)
        free_arr(cub->map);
    free_texture(cub);
}

void free_only_cub(t_cub *cub)
{
    if(cub)
        free(cub);
    exit(printf("Malloc error\n"));
}

