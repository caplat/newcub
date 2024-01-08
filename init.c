/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:55:03 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/08 12:15:07 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init(t_map *cub, t_player *player)
{
    cub->map = NULL;
    cub->horizontale = 0;
    cub->verticale = 0;
    player->position.x = 0;
    player->position.y = 0;
    player->pixel_coord.x = 0;
    player->pixel_coord.y = 0;
}

