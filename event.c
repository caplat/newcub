/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:18:50 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/19 18:19:31 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void event(mlx_key_data_t event,void *content)
{
    t_mlx *mlx;

    (void)event;
    mlx = content;
    if(mlx_is_key_down(mlx->id, MLX_KEY_ESCAPE))
        mlx_close_window(mlx->id);
}