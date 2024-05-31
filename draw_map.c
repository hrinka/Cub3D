/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:42:21 by hrinka            #+#    #+#             */
/*   Updated: 2024/05/31 20:20:14 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	draw_rectangle(int x, int y, t_cub3d *data, uint32_t color)
{
	int	i;
	int	j;

	i = x;
	j = y;
	while (y < data->map.size_shape + j)
	{
		x = i;
		while (x < data->map.size_shape + i)
		{
			mlx_put_pixel(data->map.img_map, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_map_2(t_cub3d *data, int mode, int i, int j)
{
	if (data->map.map[j][i] == '1')
		draw_rectangle(i * data->map.size_shape, j * data->map.size_shape, data,
			0xFFFFFFFF);
	if (data->map.map[j][i] == '0' || (mode == 0 && data->map.map[j][i] == 'P'))
		draw_rectangle(i * data->map.size_shape, j * data->map.size_shape, data,
			0x000000FF);
	if (data->map.map[j][i] == ' ')
		draw_rectangle(i * data->map.size_shape, j * data->map.size_shape, data,
			0xFF000033);
	if (data->map.map[j][i] == 'P' && mode)
	{
		draw_rectangle(i * data->map.size_shape, j * data->map.size_shape, data,
			0x000000FF);
		mlx_put_pixel(data->map.img, data->map.px = (i * data->map.size_shape)
			+ (data->map.size_shape / 2),
			data->map.py = (j * data->map.size_shape)
			+ (data->map.size_shape / 2), 0xFF0000FF);
	}
}

void	draw_map(t_cub3d *data, int mode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->map.height_map)
	{
		i = 0;
		while (i < data->map.width_map)
		{
			draw_map_2(data, mode, i, j);
			i++;
		}
		j++;
	}
}

void	draw_view_angle(t_cub3d *data)
{
	int		i;
	float	ray_angle;
	int		id_ray;

	i = 0;
	ray_angle = data->player.angle - (VIEW_ANGLE / 2);
	if (ray_angle < 0)
		ray_angle = 360 + ray_angle;
	id_ray = 0;
	while (i < data->render.number_rays)
	{
		if (ray_angle >= 360)
			ray_angle -= 360;
		check_ray_draw(data, ray_angle, id_ray);
		id_ray++;
		ray_angle += (VIEW_ANGLE / data->render.number_rays);
		i++;
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
