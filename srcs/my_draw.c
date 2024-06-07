/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:04:16 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/08 02:04:50 by hirosuzu         ###   ########.fr       */
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
