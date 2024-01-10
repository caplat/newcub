/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:52:53 by derblang          #+#    #+#             */
/*   Updated: 2024/01/04 12:43:30 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_arr(char **arr)
{
    int i;

    i = -1;
    while(arr[++i])
        printf("%s\n", arr[i]);
}


int ft_arrlen(char **map)
{
    int i;

    i = 0;
    if(!map)
        return (0);
    while(map[i] != NULL)
        i++;
    //printf("%d\n",i);
    return(i);
}

void free_arr(char **map)
{
    if(map == NULL)
        return;
    int i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}


int count_line(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return(i);
}
int absolute(int nb)
{
    if(nb < 0)
        nb = -nb;
    return(nb);
}