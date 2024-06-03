/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:52:59 by ahajji            #+#    #+#             */
/*   Updated: 2024/05/31 20:46:48 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	to_rad(float degree)
{
	return (degree * (M_PI / 180));
}

void	draw_line_dda(t_cub3d *data, float x2, float y2, uint32_t color)
{
	float	dx;
	float	dy;
	float	x1;
	float	y1;
	int		i;

	i = 0;
	x1 = data->map.px;
	y1 = data->map.py;
	dx = x2 - x1;
	dy = y2 - y1;
	if (fabs(dx) > fabs(dy))
		data->render.steps = fabs(dx);
	else
		data->render.steps = fabs(dy);
	data->render.increamentx = dx / data->render.steps;
	data->render.increamenty = dy / data->render.steps;
	while (i <= data->render.steps)
	{
		mlx_put_pixel(data->map.img_map, round(x1), round(y1), color);
		x1 += data->render.increamentx;
		y1 += data->render.increamenty;
		i++;
	}
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y1 - y2), 2)));
}
