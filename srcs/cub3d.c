/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:24:58 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/13 23:26:13 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data(t_cub3d *data)
{
	// data->map.map[data->player.i][data->player.j] = 'P';
	if (data->player.direction == 'N')
		data->player.angle = 270;
	else if (data->player.direction == 'S')
		data->player.angle = 90;
	else if (data->player.direction == 'W')
		data->player.angle = 180;
	else
		data->player.angle = 0;
	data->ray.number_rays = WIDTH_WIN;//光線の数
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

void	print_data(t_cub3d *data)
{
	printf("Player position: x = %f, y = %f\n", data->player.pos_x, data->player.pos_y);
	printf("Player angle: %f\n", data->player.angle);
	printf("Player direction: %c\n", data->player.direction);
	printf("Player i: %d, j: %d\n", data->player.i, data->player.j);
	printf("Player old_x: %f\n", data->map.old_x);
	printf("shape : %d\n", data->map.size_shape);
	printf("size_map : %d\n", data->map.size_map);
	printf("height_map : %d\n", data->map.height_map);
	printf("width_map : %d\n", data->map.width_map);
	// printf("number_rays : %f\n", data->render.number_rays);
	// printf("distance_horz : %f\n", data->render.distance_horz);
	// printf("distance_vert : %f\n", data->render.distance_vert);
	// printf("hores_inters_x : %f\n", data->render.hores_inters_x);
	// printf("hores_inters_y : %f\n", data->render.hores_inters_y);
	// printf("next_hor_inters_x : %f\n", data->render.next_hor_inters_x);
}

void print_map(char **map) {
    int i = 0;
    while (map[i]) {
        printf("%s", map[i]);
        i++;
    }
	printf("\n");
}

void	my_draw(void *param)
{
	t_cub3d	*data;

	data = (t_cub3d *)param;

	print_data(data);
	controle_angle(data);
	controle_player(data);
	draw_ceil_floor(data);
	raycasting(data);
	(mlx_image_to_window(data->mlx, data->map.img_map, 0, 0));
// 	if (!data->map.img_map)
// 		return (1);
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
	init_data(&data);
	printf("data init\n");
	init_textures(data.mlx, &data);
	// print_world_map(&data, data.map.world_map);
	printf("textures init\n");
	data.map.img_map = mlx_new_image(data.mlx, data.map.size_map, data.map.size_map);
	data.map.img = mlx_new_image(data.mlx, WIDTH_WIN, HEIGHT_WIN);
	if (!data.map.img || (mlx_image_to_window(data.mlx, data.map.img, 0, 0)))
		return (1);
	my_draw(&data);
	mlx_loop_hook(data.mlx, my_draw, &data);
	mlx_close_hook(data.mlx, close_callback, NULL);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_cub_data(&data);
	return (0);
}
