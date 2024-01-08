/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:30:02 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/08 14:18:05 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_arr(char **arr)
{
    int i;

    i = -1;
    while(arr[++i])
        printf("%s\n",arr[i]);
}

int count_line(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return(i);
}

void free_arr(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int absolute(int nb)
{
    if(nb < 0)
        nb = -nb;
    return(nb);
}

void print_nb_arr(int *tab)
{
    int i;

    i = -1;
    while(tab[++i])
    {
        printf("%d : %d\n",i,tab[i]);
    }
}

// void free_tab(int *tab,int count)
// {
//     int i;

//     i = 0;
//     while(i < count)
//     {
//         free(tab[i]);
//         i++;
//     }
//     free(tab);
// }

static void do_cpy(char **map,char **map_cpy)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            map_cpy[i][j] = map[i][j];
            j++;
        }
        map_cpy[i][j] = '\0';
        i++;
        j = 0;
    }
}

char ** map_cpy(char **map,int verticale)
{
    char **new_map;
    int i = -1;

    new_map = malloc(sizeof(char*) * verticale + 1);
    if(new_map == NULL)
    {
        ft_puterror("failed allocation new_map");
        return NULL;
    }
    while(++i < verticale)
    {
        new_map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
        if(!new_map[i])
        {
            free_arr(new_map);
            ft_puterror("failed allocation new_map[i]");
            return(NULL);
        }
    }
    do_cpy(map,new_map);
    return(new_map);
}