/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:55:03 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/08 15:59:06 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init(t_cub *cub, t_player *player)
{
    cub->map = NULL;
    cub->horizontale = 0;
    cub->verticale = 0;
    player->position.x = 0;
    player->position.y = 0;
    player->pixel_coord.x = 0;
    player->pixel_coord.y = 0;
    cub->floor_color = NULL;
    cub->ceilling_color = NULL;
    cub->pathEast = NULL;
    cub->pathNorth = NULL;
    cub->pathWest = NULL;
    cub->pathSouth =NULL;
    cub->south_tex = NULL;
    cub->north_tex = NULL;
    cub->west_tex = NULL;
    cub->east_tex = NULL;
}

