/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_damla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:27:28 by derblang          #+#    #+#             */
/*   Updated: 2024/01/08 17:13:50 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static char *read_file_lines(int fd, t_cub *cub) 
// {
//     char *buf;
//     char *temp;
//     char *newbuf;
//     (void)cub;

//     buf = malloc(sizeof(char));
//     if (!buf)
//         return NULL;
//     buf[0] = '\0';
//     while (1) 
//     {
//         temp = get_next_line(fd);
//         if (temp == NULL)
//             break;
//         //get_color(temp, cub);
//         free(temp);
//         newbuf = ft_strjoin(buf, temp);
//         //free(temp);
//         free(buf);
//         buf = newbuf;
//     }
//     return buf;
// }

// char **read_map(char *file, t_cub *cub)
// {
//     int fd;
//     char **arr;
//     char *buf;

   
//     if((fd = ft_open_fd(file)) < 0)
//         return NULL;
//     buf = read_file_lines(fd, cub);
//     if(buf == NULL)
//     {
//         printf("Buf is NULL\n");
//         return(NULL);
//     }    
    
//     arr = ft_split(buf, '\n');
//     free(buf);
//     close(fd);
//     return (arr);
// }

// static char *read_file_lines(int fd) 
// {
//     char *buf;
//     char *temp;
//     char *newbuf;

//     buf = malloc(sizeof(char));
//     if (!buf)
//         return NULL;
//     buf[0] = '\0';
//     while (1) 
//     {
//         temp = get_next_line(fd);
//         if (temp == NULL)
//             break;
//         newbuf = ft_strjoin(buf, temp);
//         free(temp);
//         free(buf);
//         buf = newbuf;
//     }
//     return buf;
// }

// char **read_map(char *file)
// {
//     int fd;
//     char **arr;
//     char *buf;

//     if((fd = ft_open_fd(file)) < 0)
//         return NULL;
//     buf = read_file_lines(fd);
//     arr = ft_split(buf, '\n');
//     free(buf);
//     close(fd);
//     return (arr);
// }


// void find_pos(char **map,t_player *player)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while(map[i])
//     {
//         while(map[i][j])
//         {
//             if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' 
//                 || map[i][j] == 'W')
//             {
//                 player->position.x = j;
//                 player->position.y = i;
//                 player->pixel_coord.x = (j * cellsize) + (cellsize / 2);
//                 player->pixel_coord.y = (i * cellsize) + (cellsize / 2);
//             }
//             j++;
//         }
//         i++;
//         j = 0;
//     }
// }



void check_all_map(char *file,t_cub *cub)
{
    // t_cub *cub;
    // char **map;
    
    // cub = malloc(sizeof(t_cub));
    // if(!cub)
    //     printf("Map memory allocation problem\n");
    cub->map = read_map(file);
    if(cub->map == NULL)
    {
        // free(cub);
        ft_puterror("Error reading the map\n");
    }
    // cub->map = get_map_description(cub->map);
    // if(cub->map == NULL)
    // {
    //     free_arr(cub->map);
    //     // free(cub);
    //     //free_only_cub(cub);
    //     ft_puterror("Error\nInvalid map texture\n");
    // }
    // if(check_map_components(cub->map) == -1)
    // {
    //     free_arr(cub->map);
    //     // free(cub);
    //     //free_only_cub(cub);
    //     ft_puterror("Error\nInvalid map!\n");
    // }
    // check_map_color(map, cub);  
    // check_map_texture(map, cub);
    // free_arr(map);
    
    // return (*cub);
}