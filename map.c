/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:27:28 by derblang          #+#    #+#             */
/*   Updated: 2024/01/10 12:06:32 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


static char *read_file_lines(int fd) 
{
    char *buf;
    char *temp;
    char *newbuf;

    buf = malloc(sizeof(char));
    if (!buf)
        return NULL;
    buf[0] = '\0';
    while (1) 
    {
        temp = get_next_line(fd);
        if (temp == NULL)
            break;
        newbuf = ft_strjoin(buf, temp);
        free(temp);
        free(buf);
        buf = newbuf;
    }
    return buf;
}
char **read_map(char *file)
{
    int fd;
    char **arr;
    char *buf;

    if((fd = ft_open_fd(file)) < 0)
        return NULL;
    buf = read_file_lines(fd);
    arr = ft_split(buf, '\n');
    free(buf);
    close(fd);
    return (arr);
}


void find_pos(char **map,t_player *player)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' 
                || map[i][j] == 'W')
            {
                player->position.x = j;
                player->position.y = i;
                player->pixel_coord.x = (j * cellsize) + 32;
                player->pixel_coord.y = (i * cellsize) + 32;
            }
            j++;
        }
        i++;
        j = 0;
    }
}



void check_all_map(char *file, t_cub *cub)
{
    char **map;
    
    map = read_map(file);
    if(map == NULL)
    {
        ft_puterror("Error reading the map\n");
    }
    cub->map = get_map_description(map);
    if(cub->map == NULL)
    {
        free_arr(map);
        ft_puterror("Error\nInvalid map texture\n");
    }
    if(check_map_components(cub->map) == -1)
    {
        free_arr(map);
      
        ft_puterror("Error\nInvalid map!\n");
    }
     check_map_color(map, cub);  
     check_map_texture(map, cub);
}





