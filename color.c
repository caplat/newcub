/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:42:31 by derblang          #+#    #+#             */
/*   Updated: 2024/01/09 14:45:25 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//Check if there is another char or space in the rgb
void check_color_arr(char **arr)
{
    int i;
    int j;

    i = -1;
    j = -1;
    
    while(arr[++i])
    {
        while(arr[i][++j])
        {
            if(ft_isalpha(arr[i][j]))
            {
                ft_puterror("Error\nWrong character in the color\n");
                exit(0);
            }
        }
        j = -1;
    }
    if(i < 3)
        ft_puterror("Missing character in the color\n");
}

static int is_color_in_range(int value) {
    return (value >= 0 && value <= 255);
}
void convert_rgb(char *line, t_cub *cub, char c)
{
    char **colors;
    int i;

    while (!ft_isdigit(*line))
        line++;
    colors = ft_split(line, ',');
    check_color_arr(colors);
    if (c == 'F')
    {
        i = 0;
        while(i < 3)
        {
            cub->floor[i] = ft_atoi(colors[i]);
            if (!is_color_in_range(cub->floor[i]))
                printf("Error: Floor color component %d is out of range (0-255).\n", cub->floor[i]);
            i++;
        }
    } else if (c == 'C')
    {
        i = 0;
        while(i < 3)
        {
            cub->ceilling[i] = ft_atoi(colors[i]);
            if(!is_color_in_range(cub->ceilling[i]))
                printf("Error: Ceilling color component %d is out of range (0-255).\n", cub->ceilling[i]);
            i++;
        }
    }
    free_arr(colors);
}


void get_color(char *line, t_cub *cub) {
    int i = 0;
    while (line[i] && ft_isspace(line[i]))
        i++;
    if (line[i] == 'C' || line[i] == 'F') {
        convert_rgb(line + i + 1, cub, line[i]);
    } else {
        printf("Invalid color code\n");
    }
}