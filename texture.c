/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:11 by derblang          #+#    #+#             */
/*   Updated: 2024/01/10 13:27:09 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void check_map_texture(char **map, t_cub *cub)
{
    int i;
    i = 0;
    while(map[i])
    {
        int j = 3;
        while(map[i][j] == ' ')
            ++j;
        if (map[i][0] == 'N' && map[i][1] == 'O')
        {
            cub->pathNorth = map[i] + j;
             printf("pathNorth -> %s\n", cub->pathNorth);
          // cub->north_tex = mlx_load_png(cub->pathNorth);
        }
        else if (map[i][0] == 'S' && map[i][1] == 'O')
        {
            cub->pathSouth = map[i] + j;
            printf("pathSouth -> %s\n", cub->pathSouth);
           // cub->south_tex = mlx_load_png(cub->pathSouth);
        }
          else if (map[i][0] == 'W' && map[i][1] == 'E')
        {
           cub->pathWest = map[i] + j;
           printf("pathWest  -> %s\n", cub->pathWest);
        }
          else if (map[i][0] == 'E' && map[i][1] == 'A')
        {
            cub->pathEast = map[i] + j;
            printf("pathEast  -> %s\n", cub->pathEast);
        }
        i++;
    }
}

void check_map_color(char **map, t_cub *cub)
{
    int i = 0;
    
    while(map[i])
    {
        int j = 1;
        while(map[i][j] == ' ')
            j++;
        if(map[i][0] == 'F' )
        {
            get_color(map[i], cub);
            cub->floor_color = map[i] + j;
            printf("Floor color -----> %s\n", cub->floor_color);
        }
        else if(map[i][0] == 'C')
        {
            get_color(map[i], cub);
            cub->ceilling_color = map[i] + j;
            printf("Ceilling color---> %s\n", cub->ceilling_color);
        }
        i++;
    }
}
