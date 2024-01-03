/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:23:31 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/03 14:34:39 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_screen(t_mlx *mlx)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(x < WIDTH)
    {
        while(y < HEIGHT)
        {
            mlx_put_pixel(mlx->screen,x,y,G025);
            y++;
        }
        x++;
    }
}