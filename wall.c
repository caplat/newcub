/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:10:37 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/08 15:06:22 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void check_wall_n(char **map)
{
    int j;

    j = 0;
    while(map[0][j])
    {
        if(map[0][j] != '2' && map[0][j] != ' ')
        {    
            ft_puterror("North wall not closed");
        }
        j++;
    }
}

static void check_wall_s(char ** map)
{
    int last_wall;
    int j;

    last_wall = 0;
    j = 0;
    while(map[last_wall + 1])
        last_wall++;
    while(map[last_wall][j])
    { 
        if(map[last_wall][j] != '2' && map[last_wall][j] != ' ')
        {    
            ft_puterror("South wall not closed");
        }
        j++;
    }
}

static void check_wall_sides(char **map)
{
    int i;

    i = 1;
    while(map[i])
    {
        if((map[i][0] != '2' && map[i][0] != ' ') || (map[i][ft_strlen(map[i]) - 1] != '2' 
            && map[i][ft_strlen(map[i]) -1] != ' '))
        {
            ft_puterror("Sides wall not closed");
        }
        i++;
    }  
}

static void check_outline(char **map,t_cub *cub)
{
    t_point begin;
    t_point var;

    var.x = 0;
    var.y = 0;
    while(map[var.x])
    {
        while(map[var.x][var.y])
        {
            if(map[var.x][var.y] == '1')
            {
                begin.x = var.x;
                begin.y = var.y;
                fill_bis(map,begin,cub);
                printf("\n");
                print_arr(map);
                return;
            }   
            var.y++;
        }
        var.x++;
        var.y = 0;
    }
}

void check_wall(char **map,t_cub *cub)
{
    char **map_bis;

    map_bis = map_cpy(map,cub->verticale);
    printf("\n");
    print_arr(map_bis);
    check_outline(map_bis,cub);
    check_wall_n(map_bis);
    check_wall_s(map_bis);
    check_wall_sides(map_bis);
    free_arr(map_bis);
}