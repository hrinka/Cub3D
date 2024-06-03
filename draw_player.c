/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:56:23 by ahajji            #+#    #+#             */
/*   Updated: 2024/05/31 20:04:17 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_cub3d *data)
{
	int	i;
	int	j;

	i = data->map.py - 1;
	j = 0;
	while (i < data->map.py + 1)
	{
		j = data->map.px - 1;
		while (j < data->map.px + 1)
		{
			mlx_put_pixel(data->map.img_map, j, i, 0xFF0000FF);
			j++;
		}
		i++;
	}
}
