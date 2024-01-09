/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:07:05 by derblang          #+#    #+#             */
/*   Updated: 2024/01/09 12:35:59 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void fill(char **map,t_point cur,int horizontale,int verticale)
{
    t_point size;

    size.x = verticale;
    size.y = horizontale;
    if((map[cur.x][cur.y] != ' ') || cur.y < 0 || cur.y >= size.y
        || cur.x < 0 || cur.x >= size.x)
        return;
    if(map[cur.x][cur.y] == ' ' && ((cur.x > 0 && map[cur.x - 1][cur.y] != '1' 
        && map[cur.x - 1][cur.y] != ' ' && map[cur.x - 1][cur.y] != 'F') 
        || ( cur.x < size.x - 1 && map[cur.x + 1][cur.y] != '1' 
        && map[cur.x + 1][cur.y] != ' ' && map[cur.x + 1][cur.y] != 'F') 
        || (cur.y > 0 && map[cur.x][cur.y - 1] != '1' && map[cur.x][cur.y - 1] 
        != ' ' && map[cur.x][cur.y - 1] != 'F') || (cur.y < size.y - 1 
        && map[cur.x][cur.y + 1] != '1' && map[cur.x][cur.y + 1] != ' ' 
        && map[cur.x][cur.y + 1] != 'F')))
    {    
        printf("\nx : %d\ny : %d\n",cur.x,cur.y);
        // printf("->%c\n",map[cur.x][cur.y + 1]);
        ft_puterror("space not closed");
    }
    map[cur.x][cur.y] = 'F';
    if(cur.x > 0)
        fill(map,(t_point){cur.x - 1,cur.y},horizontale,verticale);
    if(cur.x < size.x - 1)
        fill(map,(t_point){cur.x + 1,cur.y},horizontale,verticale);
    fill(map,(t_point){cur.x,cur.y - 1},horizontale,verticale);
    fill(map,(t_point){cur.x,cur.y + 1},horizontale,verticale);      
}

void flood_fill(char **map,int horizontale,int verticale)
{
    t_point begin;
    char **map_ter;
    int i;
    int j;

    i = 0;
    j = 0;
    map_ter = map_cpy(map,verticale);
    while(map_ter[i])
    {
        while(map_ter[i][j])
        {
            if(map_ter[i][j] == ' ')
            {
                begin.x = i;
                begin.y = j;
                fill(map_ter,begin,horizontale,verticale);
            }
            j++;
        }
        i++;
        j = 0;
    }
    printf("\n");
    print_arr(map_ter);
    free_arr(map_ter);
}

void fill_bis(char **map,t_point cur,t_cub *cub)
{
    t_point size;

    size.x = cub->verticale;
    size.y = cub->horizontale;
    // printf("start.x :%d\nstart.y :%d\n",start.x,start.y);
    if((map[cur.x][cur.y] != '1') || cur.y < 0 || cur.y >= size.y
        || cur.x < 0 || cur.x >= size.x)
        return;
    map[cur.x][cur.y] = '2';
    // printf("cur.x :%d\ncur.y :%d\n",cur.x,cur.y);
    // printf("\n");
    if(cur.x > 0)
        fill_bis(map, (t_point){cur.x - 1, cur.y},cub);
    if(cur.x < size.x - 1)
	    fill_bis(map, (t_point){cur.x + 1, cur.y},cub);
    if(cur.y > 0)
	    fill_bis(map, (t_point){cur.x, cur.y - 1},cub);
    if(cur.y < size.y - 1)
	    fill_bis(map, (t_point){cur.x, cur.y + 1},cub);
    if(cur.x > 0 && cur.y > 0)
       fill_bis(map, (t_point){cur.x - 1, cur.y - 1},cub);
    if(cur.x > 0 && cur.y < size.y - 1)
        fill_bis(map, (t_point){cur.x - 1, cur.y + 1},cub);
    if(cur.x < size.x - 1 && cur.y > 0)
        fill_bis(map, (t_point){cur.x + 1, cur.y - 1},cub);
    if(cur.x < size.x - 1 && cur.y < size.y - 1)
         fill_bis(map, (t_point){cur.x + 1, cur.y + 1},cub);
}