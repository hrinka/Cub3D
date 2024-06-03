/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:47:08 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/01 21:51:39 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_mouse(double xp, double yp, void *param)
{
	t_cub3d	*data;

	data = (t_cub3d *)param;
	if (xp >= 0 && xp <= WIDTH_WIN && yp >= 0 && yp <= HEIGHT_WIN)
	{
		if (xp > data->map.old_x)
		{
			data->player.angle += (SPEED_ROTATE + 0.1);
			if (data->player.angle >= 360)
				data->player.angle -= 360;
		}
		else
		{
			data->player.angle -= SPEED_ROTATE;
			if (data->player.angle <= 0)
				data->player.angle += 360;
		}
		data->map.old_x = xp;
	}
}
