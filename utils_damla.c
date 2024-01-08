/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_damla.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:14:49 by derblang          #+#    #+#             */
/*   Updated: 2024/01/08 15:47:26 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// static void do_cpy(char **map,char **map_cpy)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while(map[i])
//     {
//         while(map[i][j])
//         {
//             map_cpy[i][j] = map[i][j];
//             j++;
//         }
//         map_cpy[i][j] = '\0';
//         i++;
//         j = 0;
//     }
// }

// char ** map_cpy(char **map,int verticale)
// {
//     char **new_map;
//     int i = -1;

//     new_map = malloc(sizeof(char*) * verticale + 1);
//     if(new_map == NULL)
//     {
//         ft_puterror("failed allocation new_map");
//         return NULL;
//     }
//     while(++i < verticale)
//     {
//         new_map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
//         if(!new_map[i])
//         {
//             free_arr(new_map);
//             ft_puterror("failed allocation new_map[i]");
//             return(NULL);
//         }
//     }
//     do_cpy(map,new_map);
//     return(new_map);
// }

static int ft_arrlen(char **map)
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

char	**ft_arrdup(char **arr)
{
	char	**dup;
	int		arr_len;

	dup = NULL;
	if (!arr)
		return (NULL);
	arr_len = ft_arrlen(arr);
	if (!arr_len)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!dup)
		return (NULL);
	dup[arr_len] = NULL;
	while (arr_len--)
	{
		dup[arr_len] = ft_strdup(arr[arr_len]);
		if (!dup[arr_len])
		{
			free(dup);
			return (NULL);
		}
	}
	return (dup);
}
