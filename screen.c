/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:23:31 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/30 16:32:52 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_screen_column(t_mlx *mlx)
{
    int x;
    int y;
    int start_y;
    int column;

    column = WIDTH / mlx->nb_rays;
    x = 0;
    y = 0;
    start_y = (HEIGHT / 2) - (mlx->wall_height / 2);
    while(x < column)
    {
        mlx_put_pixel(mlx->screen, x, start_y + (y * mlx->wall_height) / column, G025);
        x++;
    }
}
