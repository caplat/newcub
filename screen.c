/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:23:31 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/31 12:06:22 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_screen(t_mlx *mlx)
{
    int x;
    int y;

    x = 0;
    while(x < WIDTH)
    {
        y = (HEIGHT / 2) / mlx->dist_player_screen;
        while(y < HEIGHT)
        {
            mlx_put_pixel(mlx->img_ray,x,y, G025);
            y++;
        }
        x++;
    }
}