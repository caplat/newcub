/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:50:31 by derblang          #+#    #+#             */
/*   Updated: 2024/01/10 16:06:18 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void find_dim(char **map,t_cub *cub)
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

static void find_angle(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(mlx->cub->map[i])
    {
        while(mlx->cub->map[i][j])
        {
            if(mlx->cub->map[i][j] == 'N')
                mlx->player->angle = M_PI / 2 + M_PI;
            if(mlx->cub->map[i][j] == 'S')
                mlx->player->angle = (3 * M_PI) / 2 + M_PI;
            if(mlx->cub->map[i][j] == 'E')
                mlx->player->angle = M_PI + M_PI;
            if(mlx->cub->map[i][j] == 'W')
                mlx->player->angle = 0 + M_PI;
            j++;
        }
        i++;
        j = 0;
    }
}

int main(int argc, char **argv)
{
    t_mlx mlx;
    t_player player;
    t_cub cub;
    
    init(&cub, &player);
    mlx.cub = &cub;
    mlx.player = &player;
    mlx.tab = malloc(sizeof(int) * (WIDTH));
    mlx.tab_wall = malloc(sizeof(t_orient) * WIDTH);
    check_args(argc);
	check_file_extension(argv[1]);
    check_all_map(argv[1], &cub);
     if(cub.map == NULL)
     {
        ft_puterror("Error\nMap cant be read!\n");
        free_arr(cub.map);
     }
    //  if(cub.map != NULL)
    //     print_arr(cub.map);
    find_pos(cub.map, &player);
    printf("posx : %d\nposy : %d\n",mlx.player->position.x,mlx.player->position.y);
    printf("pixcoord.x : %d\npixcoord.y : %d\n",player.pixel_coord.x,player.pixel_coord.y);
    find_angle(&mlx);
    printf("playerangle :%f\n",mlx.player->angle);
    find_dim(cub.map, &cub);
    printf("\nverticale : %d\nhorizontale : %d\n",cub.verticale,cub.horizontale);
    print_arr(cub.map);
    flood_fill(cub.map,cub.horizontale,cub.verticale);
    // printf("\n");
    open_window(&mlx);
    free_arr(cub.map);
    free(mlx.tab);
    free(mlx.tab_wall);
    return 0;
 }
