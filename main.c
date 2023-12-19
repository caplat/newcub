/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:52:54 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/19 18:33:36 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void find_dim(char **map,t_map *cub)
{
    int i;
    int j;

    i = 0;
    j = 0;
    cub->verticale = count_line(map);
    while(map[i])
    {
        while(map[i][j])
            j++;
        if(cub->horizontale < j)
            cub->horizontale = j;
        i++;
        j = 0;
    }
    if(cub->horizontale == 0 && cub->verticale == 0)
        ft_puterror("map is empty");
}

int main(int argc,char **argv)
{
    t_mlx mlx;
    t_map cub;
    t_player player;

    init(&cub, &player);
    mlx.cub = &cub;
    mlx.player = &player;
    check_args(argc);
    check_file_extension(argv[1]);
    cub.map = read_map(argv[1]);
    check_map(cub.map);
    find_pos(cub.map,&player);
    printf("posx : %d\nposy : %d\n",mlx.player->position.x,mlx.player->position.y);
    printf("pixcoord.x : %d\npixcoord.y : %d\n",player.pixel_coord.x,player.pixel_coord.y);
    find_dim(cub.map, &cub);
    printf("\nverticale : %d\nhorizontale : %d\n",cub.verticale,cub.horizontale);
    print_arr(cub.map);
    open_window(&mlx);
    free_arr(cub.map);
    return(0);
}

