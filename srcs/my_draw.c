/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:04:16 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/08 17:23:31 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_wall(t_cub3d *data, t_ray *ray, int x)
{
	int line_height = (int)(HEIGHT_WIN / ray->wall_dist);
	int draw_start = -line_height / 2 + HEIGHT_WIN / 2;
	if (draw_start < 0)
		draw_start = 0;
	int draw_end = line_height / 2 + HEIGHT_WIN / 2;
	if (draw_end >= HEIGHT_WIN)
		draw_end = HEIGHT_WIN - 1;
	int color;
	if (ray->side == 1)
	    color = 0xAAAAAA;
	else
    	color = 0xFFFFFF;
	draw_line(data, x, draw_start, draw_end, color);
}

void	draw_line(t_cub3d *data, int x, int start, int end, int color)
{
	int	y;

	y = start;
	// printf("start: %d\n", start);
	// printf("end: %d\n", end);
	while (y < end)
	{
		mlx_put_pixel(data->map.img, x, y, color);
		y++;
	}
}

void	draw_ceil_floor(t_cub3d *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT_WIN)
	{
		i = 0;
		while (i < WIDTH_WIN)
		{
			if (j < HEIGHT_WIN / 2)
				mlx_put_pixel(data->map.img, i, j, data->textures.sky_hex);
			else
				mlx_put_pixel(data->map.img, i, j, data->textures.floor_hex);
			i++;
		}
		j++;
	}
}
