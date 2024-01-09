/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:29:43 by derblang          #+#    #+#             */
/*   Updated: 2023/12/18 13:46:41 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void texture_check(char *line, int *count)
{
	
	if(line[2] == ' ')
	{
		if(line[0] == 'N' && line[1] == 'O')
        	(*count)++;
    	else if(line[0] == 'S' && line[1] == 'O')
        	(*count)++;
    	else if(line[0] == 'W' && line[1] == 'E')
     		(*count)++;
    	else if(line[0] == 'E' && line[1] == 'A')
        	(*count)++;
	}
	else if(line[1] == ' ')
	{
		if(line[0] == 'F' )
			(*count)++;
		else if(line[0] == 'C' )
			(*count)++;
	}
}

char	**get_map_description(char **map)
{
	size_t	i;
	int		count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		texture_check(map[i], &count);
		if (count == 6)
		{
			while(map[++i])
			{
				if(map[i][0] == '\n')
					continue;
				if(ft_strstr(map[i], "1\0"))
					return (ft_arrdup(map + i));
				else
					return (NULL);
			}
		}	
	}
	return (NULL);
}