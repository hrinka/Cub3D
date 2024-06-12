/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:17:09 by ahajji            #+#    #+#             */
/*   Updated: 2024/06/13 04:41:22 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    controle_angle(t_cub3d *data)
{
	
	mlx_cursor_hook(data->mlx, move_mouse, (void *)data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player.angle += SPEED_ROTATE;
		if (data->player.angle >= 360)
			data->player.angle -= 360;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player.angle -= SPEED_ROTATE;
		if (data->player.angle <= 0)
			data->player.angle += 360;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		exit(0);
}

void    move_player(t_cub3d *data, float new_x, float new_y)
{
	// 新しい位置が壁でないかチェック
	if (check_wall(data, new_x, new_y))
	{
		printf("Old Position: (%f, %f), New Position: (%f, %f)\n", data->player.pos_x, data->player.pos_y, new_x, new_y);
		data->player.pos_x = new_x;
		data->player.pos_y = new_y;
	}
	else
	{
		// 位置が壁の場合は、それ以上先に進めない
		printf("Hit wall at (%f, %f)\n", new_x, new_y);
	}
}

void    controle_player(t_cub3d *data)
{
	float new_x = data->player.pos_x;
	float new_y = data->player.pos_y;

	// check_wall_2(data, &new_x, &new_y);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		new_x += data->player.dir_x * MOVE_STEP;
		new_y += data->player.dir_y * MOVE_STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		new_x -= data->player.dir_x * MOVE_STEP;
		new_y -= data->player.dir_y * MOVE_STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		new_x -= data->player.plane_x * MOVE_STEP;
		new_y -= data->player.plane_y * MOVE_STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		new_x += data->player.plane_x * MOVE_STEP;
		new_y += data->player.plane_y * MOVE_STEP;
	}
	move_player(data, new_x, new_y);
}

int check_wall(t_cub3d *data, float x, float y) {
	// int map_x = (int)(x / data->map.size_shape);
	// int map_y = (int)(y / data->map.size_shape);
	//--------------------ここから--------------------
	int map_x = (int)(x); //hirosuzu
	int map_y = (int)(y); //hirosuzu

	// 確認用のコード。プロえふで中身を確認しました。
	// sleep(1)を使っているので、loop中のキー操作のタイミングで止まります。
	// (int)(x / data->map.size_shape)の計算の意味がよく分からなかっですが、
	// 単純にxyを四捨五入(int型にキャスト)すれば大丈夫なコードに思えるので勝手に修正しました。
	// こちらはりんかさんが確認して再修正していただいて構いません。
	// printf("Map: (%d, %d)\n", map_x, map_y);
	// printf("x: %f, y: %f\n", x, y);
	// printf("Map size: %d\n", data->map.size_shape);
	// printf("Map width: %d\n", data->map.width_map);
	// printf("Map height: %d\n", data->map.height_map);
	// sleep(1);
	//--------------------ここまで--------------------
	
	// マップの範囲を超えた場合の処理
	if (map_x < 0 || map_x >= data->map.width_map || map_y < 0 || map_y >= data->map.height_map) {
		printf("Out of map bounds: (%d, %d)\n", map_x, map_y);
		return 0;
	}

	// 壁の衝突判定
	// if (data->map.world_map[map_y][map_x] == 1) どちらでもいいです
	if (data->map.map[map_y][map_x] == '1') {
		printf("Hit wall at (%d, %d)\n", map_x, map_y);
		return 0;
	}
	return 1;
}
