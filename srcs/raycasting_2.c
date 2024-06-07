/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:32:35 by ahajji            #+#    #+#             */
/*   Updated: 2024/06/07 21:56:39 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	call_raycasting(t_cub3d *data, float ray_angle, int id_ray)
{
	if (data->render.distance_horz < data->render.distance_vert)
	{
		data->render.dist = data->render.distance_horz;
		if (ray_angle >= 180 && ray_angle <= 360)
			ray_casting(data, ray_angle, id_ray, data->textures.no_texture);
		else
			ray_casting(data, ray_angle, id_ray, data->textures.so_texture);
		data->render.present_texture
			= (data->render.hores_inters_x / data->map.size_shape)
			- ((int)(data->render.hores_inters_x / data->map.size_shape));
	}
	else
	{
		data->render.dist = data->render.distance_vert;
		if (ray_angle >= 90 && ray_angle <= 270)
			ray_casting(data, ray_angle, id_ray, data->textures.ea_texture);
		else
			ray_casting(data, ray_angle, id_ray, data->textures.we_texture);
		data->render.present_texture
			= (data->render.vertcl_inters_y / data->map.size_shape)
			- ((int)(data->render.vertcl_inters_y / data->map.size_shape));
	}
}
