/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:37:30 by ahajji            #+#    #+#             */
/*   Updated: 2024/06/01 17:22:09 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_casting(t_cub3d *data, float ray_angle,
	int id_ray, mlx_image_t *img)
{
	double	height_wall;
	int		xstart;
	int		ystart;
	int		yend;

	data->render.dist = data->render.dist * cos(to_rad(ray_angle) - to_rad(data->player.angle));
	height_wall = ((data->map.size_shape) * HEIGHT_WIN) / data->render.dist;
	xstart = id_ray;
	ystart = (HEIGHT_WIN / 2) - (height_wall / 2);
	yend = (HEIGHT_WIN / 2) + (height_wall / 2);
	if (yend > HEIGHT_WIN)
		yend = HEIGHT_WIN;
	data->render.texture_offset_x = data->render.present_texture * img->width;
	data->render.wall_start = ystart;
	while (ystart < yend)
	{
		data->render.texture_offset_y = (((float)ystart - (float)data->render.wall_start)
				/ (float)height_wall) * img->height;
		if (ystart >= 0 && ystart < HEIGHT_WIN)
			mlx_put_pixel(data->map.img, xstart, (int)ystart,
				get_texel(img, data->render.texture_offset_x, data->render.texture_offset_y));
		ystart += 1;
	}
}

void	check_ray_draw_down(t_cub3d *data, float ray_angle)
{
	data->render.hores_inters_y = floor((data->map.py / data->map.size_shape) + 1)
		* data->map.size_shape;
	data->render.hores_inters_x = data->map.px + (data->render.hores_inters_y - data->map.py)
		/ tan(to_rad(ray_angle));
	data->render.next_hor_inters_y = data->render.hores_inters_y + data->map.size_shape;
	data->render.next_hor_inters_x = data->render.hores_inters_x + ((data->render.next_hor_inters_y
				- data->render.hores_inters_y) / tan(to_rad(ray_angle)));
	data->render.step_hor_y = data->map.size_shape;
	data->render.step_hor_x = data->render.next_hor_inters_x - data->render.hores_inters_x;
	while (((int)(data->render.hores_inters_x / data->map.size_shape)) < data->map.width_map
		&& ((int)(data->render.hores_inters_y / data->map.size_shape)) < data->map.height_map
		&& data->render.hores_inters_x >= 0 && data->render.hores_inters_y >= 0
		&& data->map.map[(int)(data->render.hores_inters_y
			/ data->map.size_shape)][(int)(data->render.hores_inters_x
			/ data->map.size_shape)] != '1')
	{
		data->render.hores_inters_y += data->render.step_hor_y;
		data->render.hores_inters_x += data->render.step_hor_x;
	}
}

void	check_ray_draw_up(t_cub3d *data, float ray_angle)
{
	data->render.hores_inters_y = floor((data->map.py / data->map.size_shape))
		* data->map.size_shape;
	data->render.hores_inters_x = data->map.px - ((data->map.py - data->render.hores_inters_y)
			/ tan(to_rad(ray_angle)));
	data->render.next_hor_inters_y = data->render.hores_inters_y - data->map.size_shape;
	data->render.next_hor_inters_x = data->render.hores_inters_x - ((data->render.hores_inters_y
				- data->render.next_hor_inters_y) / tan(to_rad(ray_angle)));
	data->render.step_hor_y = data->map.size_shape;
	data->render.step_hor_x = data->render.next_hor_inters_x - data->render.hores_inters_x;
	while (((int)(data->render.hores_inters_x / data->map.size_shape)) < data->map.width_map
		&& ((int)((data->render.hores_inters_y - 1)
				/ data->map.size_shape)) < data->map.height_map
		&& data->render.hores_inters_x >= 0 && data->render.hores_inters_y >= 0
		&& data->map.map[(int)((data->render.hores_inters_y - 1)
			/ data->map.size_shape)][(int)(data->render.hores_inters_x
			/ data->map.size_shape)] != '1')
	{
		data->render.hores_inters_y -= data->render.step_hor_y;
		data->render.hores_inters_x += data->render.step_hor_x;
	}
}

void check_ray_draw_right(t_cub3d *data, float ray_angle)
{
    data->render.vertcl_inters_x = floor(data->map.px / data->map.size_shape + 1) * data->map.size_shape;
    data->render.vertcl_inters_y = data->map.py - (data->map.px - data->render.vertcl_inters_x) * tan(to_rad(ray_angle));

    data->render.next_ver_inters_x = data->render.vertcl_inters_x + data->map.size_shape;
    data->render.next_ver_inters_y = data->render.vertcl_inters_y - ((data->render.vertcl_inters_x - data->render.next_ver_inters_x) * tan(to_rad(ray_angle)));

    data->render.step_ver_y = data->render.next_ver_inters_y - data->render.vertcl_inters_y;

    int map_x, map_y;
    while (true)
    {
        map_x = (int)(data->render.vertcl_inters_x / data->map.size_shape);
        map_y = (int)(data->render.vertcl_inters_y / data->map.size_shape);

        if (map_x >= data->map.width_map || map_y >= data->map.height_map ||
            data->render.vertcl_inters_x < 0 || data->render.vertcl_inters_y < 0 ||
            data->map.map[map_y][map_x] == '1') {
            break;
        }

        data->render.vertcl_inters_y += data->render.step_ver_y;
        data->render.vertcl_inters_x += data->render.step_ver_x;
    }
}


void	check_ray_draw_left(t_cub3d *data, float ray_angle)
{
	data->render.vertcl_inters_x = floor((data->map.px / data->map.size_shape))
		* data->map.size_shape;
	data->render.vertcl_inters_y = data->map.py - ((data->map.px - data->render.vertcl_inters_x)
			* tan(to_rad(ray_angle)));
	data->render.next_ver_inters_x = data->render.vertcl_inters_x - data->map.size_shape;
	data->render.next_ver_inters_y = data->render.vertcl_inters_y - ((data->render.vertcl_inters_x
				- data->render.next_ver_inters_x) * tan(to_rad(ray_angle)));
	data->render.step_ver_x = data->map.size_shape;
	data->render.step_ver_y = data->render.next_ver_inters_y - data->render.vertcl_inters_y;
	while (((int)((data->render.vertcl_inters_x - 1)
			/ data->map.size_shape)) < data->map.width_map
		&& ((int)(data->render.vertcl_inters_y / data->map.size_shape)) < data->map.height_map
		&& data->render.vertcl_inters_x >= 0 && data->render.vertcl_inters_y >= 0
		&& data->map.map[(int)(data->render.vertcl_inters_y
			/ data->map.size_shape)][(int)((data->render.vertcl_inters_x - 1)
			/ data->map.size_shape)] != '1')
	{
		data->render.vertcl_inters_y += data->render.step_ver_y;
		data->render.vertcl_inters_x -= data->render.step_ver_x;

	}
}
