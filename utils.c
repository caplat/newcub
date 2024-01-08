/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:30:02 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/08 12:12:51 by acaplat          ###   ########.fr       */
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