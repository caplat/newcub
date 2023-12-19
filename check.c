/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:19:26 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/19 17:20:52 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_args(char argc)
{
    if(argc != 2)
        ft_puterror("Put only 2 arguments!");
}

static int	ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
	{
		return (0);
	}
}

void	check_file_extension(char *file)
{
	while (*file)
	{
		if (*file == '.')
		{
			if (ft_strstr(file, ".cub"))
				return ;
		}
		file++;
	}
	ft_puterror("Map extension is wrong!");
	exit(1);
}

int	ft_open_fd(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_puterror("Problem with file");
		return(-1);	
	}
	return (fd);
}