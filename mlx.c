/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:15:22 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/19 18:31:13 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void open_window(t_mlx *mlx)
{
    // bool success;
    
    mlx->id = mlx_init(WIDTH,HEIGHT,"CUBE",true);
    if(!mlx->id)
        ft_puterror("problem with window");
    mlx->img = mlx_new_image(mlx->id,WIDTH,HEIGHT);
    mlx_image_to_window(mlx->id,mlx->img,0,0);
    mlx_key_hook(mlx->id,event,mlx);
    // success = mlx_loop_hook(mlx->id,loop,mlx);
    // if(!success)
    //     ft_puterror("loop hook failed");
    mlx_loop(mlx->id);
    mlx_terminate(mlx->id);
}