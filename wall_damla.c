/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_damla.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:57:29 by derblang          #+#    #+#             */
/*   Updated: 2024/01/08 15:40:45 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void check_wall_n(char **map)
{
    int j;

    j = 0;
    while(map[0][j] == ' ')
        j++;
    while(map[0][j])
    {
        if(map[0][j] != '1' && map[0][j] != ' ')
            ft_puterror("North wall not closed");
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
        if(map[last_wall][j] != '1' && map[last_wall][j] != ' ')
            ft_puterror("South wall not closed");
        j++;
    }
}

static void check_wall_sides(char **map)
{
    int i;

    i = 1;
    while(map[i])
    {
        // printf("test\n");
        if((map[i][0] != '1' && map[i][0] != ' ') || (map[i][ft_strlen(map[i]) - 1] != '1' 
            && map[i][ft_strlen(map[i]) -1] != ' '))
        {
            // printf("test ligne %d %c\n",i,map[i][ft_strlen(map[i]) - 1]);
            ft_puterror("Sides wall not closed");
        }
        i++;
    }  
}



static int	check_around(char **map, int i, size_t j)
{
	if (map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != ' '
		&& map[i][j - 1] != '\n')
		return (-1);
	else if (map[i][j + 1] && map[i][j + 1] != '1' && map[i][j + 1] != ' '
			&& map[i][j + 1] != '\n')
		return (-1);
	else if (map[i + 1] && j <= ft_strlen(map[i + 1]) && map[i + 1][j] != '1'
			&& map[i + 1][j] != ' ' && map[i + 1][j] != '\n')
		return (-1);
	else if (i > 1 && map[i - 1] && j <= ft_strlen(map[i - 1]) && map[i
			- 1][j] != '1' && map[i - 1][j] != ' ' && map[i - 1][j] != '\n')
		return (-1);
	return (0);
}

int	check_closed_around_space(char **map)
{
	int		i;
	//int		count;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j] && map[i][j + 1])
		{
			if (map[i][j] == ' ')
			{
                if (check_around(map, i, j) == -1)
					return (printf("Error \nInvalid map: map is not closed\n"));
            }	
			j++;
		}
		i++;
	}
	return (0);
}

void check_wall_damla(char **map)
{
    if(check_closed_around_space(map))
		ft_puterror("Check Walls: Space's are not closed!\n");
	check_wall_n(map);
    check_wall_s(map);
    check_wall_sides(map);

}