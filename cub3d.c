/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:24:58 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/01 21:50:58 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_cub3d *data)
{
	data->map.map[data->player.i][data->player.j] = 'P';
	if (data->player.direction == 'N')
		data->player.angle = 270;
	else if (data->player.direction == 'S')
		data->player.angle = 90;
	else if (data->player.direction == 'W')
		data->player.angle = 180;
	else
		data->player.angle = 0;
	data->render.number_rays = WIDTH_WIN;//光線の数
	if (WIDTH_WIN / 9 > HEIGHT_WIN / 9)//ゲームウィンドウ内でのマップの全体的なサイズを決定
		data->map.size_map = WIDTH_WIN / 9;
	else
		data->map.size_map = HEIGHT_WIN / 9;
	if (data->map.height_map > data->map.width_map)//マップ内の個々の要素（壁など）のサイズを決定
		data->map.size_shape = data->map.size_map / data->map.height_map;
	else
		data->map.size_shape = data->map.size_map / data->map.width_map;
	data->map.old_x = WIDTH_WIN;
}

void	calcul_distance(t_cub3d *data)
{
	data->render.distance_horz = distance_between_points(data->map.px, data->map.py,
			data->render.hores_inters_x, data->render.hores_inters_y);
	data->render.distance_vert = distance_between_points(data->map.px, data->map.py,
			data->render.vertcl_inters_x, data->render.vertcl_inters_y);
}

void	check_ray_draw(t_cub3d *data, float ray_angle, int id_ray)
{
	if (ray_angle > 0 && ray_angle < 180)
		check_ray_draw_down(data, ray_angle);
	else
		check_ray_draw_up(data, ray_angle);
	if (ray_angle < 90 || ray_angle > 270)
		check_ray_draw_right(data, ray_angle);
	else
		check_ray_draw_left(data, ray_angle);
	calcul_distance(data);
	call_raycasting(data, ray_angle, id_ray);
}

void	draw(void *param)
{
	t_cub3d	*data;

	data = (t_cub3d *)param;
	controle_angle(data);
	controle_player(data);
	draw_ceil_floor(data);
	draw_map(data, 0);
	draw_view_angle(data);
	draw_player(data);
}

int	main(int ac, char **av)
{
	t_cub3d	data;

	if (ac != 2)
		return (printf("Please provide a map file with .cub"),
			printf(" extenstion in the maps directory\n"), EXIT_FAILURE);
	init_game(av[1], &data);
	data.mlx = mlx_init(WIDTH_WIN, HEIGHT_WIN, "cub3d", false);
	if (!data.mlx)
		return (1);
	init_textures(data.mlx, &data);
	init_data(&data);
	data.map.img_map = mlx_new_image(data.mlx, data.map.size_map, data.map.size_map);
	data.map.img = mlx_new_image(data.mlx, WIDTH_WIN, HEIGHT_WIN);
	if (!data.map.img || (mlx_image_to_window(data.mlx, data.map.img, 0, 0)))
		return (1);
	(mlx_image_to_window(data.mlx, data.map.img_map, 0, 0));
	if (!data.map.img_map)
		return (1);
	draw_map(&data, 1);
	mlx_loop_hook(data.mlx, draw, &data);
	mlx_close_hook(data.mlx, close_callback, NULL);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_cub_data(&data);
	return (0);
}
