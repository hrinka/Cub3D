/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:24:58 by hrinka            #+#    #+#             */
/*   Updated: 2024/05/27 19:38:38 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_cub3d *data)
{
	data->map[data->player.i][data->player.j] = 'P'
	if (data->player.direction == 'N')
		data->angle = 270;
	else if (data->player.direction == 'S')
		data->angle = 90;
	else if (data->player.direction == 'W')
		data->angle = 180;
	else
		data->angle = 0;
	data->number_rays = WIDTH_WIN;//光線の数をウィンドウの幅に設定
	if (WIDTH_WIN / 9 > HEIGHT_WIN / 9)//ゲームウィンドウ内でのマップの全体的なサイズを決定
		data->size_map = WIDTH_WIN / 9;
	else
		data->size_map = HEIGHT_WIN / 9;
	if (data->height_map > data->width_map)//マップ内の個々の要素（壁など）のサイズを決定
		data->size_shape = data->size_map / data->height_map;
	else
		data->size_shape = data->size_map / data->width_map;
	data->old_x = WIDTH_WIN;
}

void	draw_map_2(t_cub3d *data, int mode, int i, int j)
{
	if (data->map[j][i] == '1')
		draw_rectangle(i * data->size_shape, j * data->size_shape, data,
			0xFFFFFFFF);
	if (data->map[j][i] == '0' || (mode == 0 && data->map[j][i] == 'P'))
		draw_rectangle(i * data->size_shape, j * data->size_shape, data,
			0x000000FF);
	if (data->map[j][i] == ' ')
		draw_rectangle(i * data->size_shape, j * data->size_shape, data,
			0xFF000033);
	if (data->map[j][i] == 'P' && mode)
	{
		draw_rectangle(i * data->size_shape, j * data->size_shape, data,
			0x000000FF);
		mlx_put_pixel(data->img, data->px = (i * data->size_shape)
			+ (data->size_shape / 2),
			data->py = (j * data->size_shape)
			+ (data->size_shape / 2), 0xFF0000FF);
	}
}

void	draw_map(t_cub3d *data, int mode)//マップ全体をループで描画
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->height_map)
	{
		i = 0;
		while (i < data->width_map)
		{
			draw_map_2(data, mode, i, j);//マップの各セルを描画。壁、空間、プレイヤー位置など
			i++;
		}
		j++;
	}
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
	data.img_map = mlx_new_image(data.mlx, data.size_map, data.size_map);
	data.img = mlx_new_image(data.mlx, WIDTH_WIN, HEIGHT_WIN);
	if (!data.img || (mlx_image_to_window(data.mlx, data.img, 0, 0)))
		return (1);
	(mlx_image_to_window(data.mlx, data.img_map, 0, 0));
	if (!data.img_map)
		return (1);
	draw_map(&data, 1);
	mlx_loop_hook(data.mlx, draw, &data);
	mlx_close_hook(data.mlx, close_callback, NULL);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_cub_data(&data);
	return (0);
}
