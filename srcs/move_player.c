/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:17:09 by ahajji            #+#    #+#             */
/*   Updated: 2024/06/08 20:28:28 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	controle_angle(t_cub3d *data) 
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

// void	controle_player(t_cub3d *data)
// {
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_W) && check_wall(data))
// 	{
// 		printf("W\n");
// 		data->map.px = data->map.px + (cos(to_rad(data->player.angle)) * MOVE_STEP);
// 		data->map.py = data->map.py + (sin(to_rad(data->player.angle)) * MOVE_STEP);
// 		printf("check_wall: %d\n", check_wall(data));
// 	}
// 	else if (mlx_is_key_down(data->mlx, MLX_KEY_S) && check_wall(data))
// 	{
// 		data->map.px = data->map.px - (cos(to_rad(data->player.angle)) * MOVE_STEP);
// 		data->map.py = data->map.py - (sin(to_rad(data->player.angle)) * MOVE_STEP);
// 	}
// 	else if (mlx_is_key_down(data->mlx, MLX_KEY_D) && check_wall(data))
// 	{
// 		data->map.px = data->map.px - cos(to_rad(90 - data->player.angle)) * MOVE_STEP;
// 		data->map.py = data->map.py + sin(to_rad(90 - data->player.angle)) * MOVE_STEP;
// 	}
// 	else if (mlx_is_key_down(data->mlx, MLX_KEY_A) && check_wall(data))
// 	{
// 		data->map.px = data->map.px + cos(to_rad(90 - data->player.angle)) * MOVE_STEP;
// 		data->map.py = data->map.py - sin(to_rad(90 - data->player.angle)) * MOVE_STEP;
// 	}
// 	printf("data->map.px: %f\n",data->map.px);
// 	printf("data->map.py: %f\n",data->map.py);
// 	printf("cos(to_rad(data->player.angle)): %f\n", cos(to_rad(data->player.angle)));
// 	printf("sin(to_rad(data->player.angle)): %f\n", sin(to_rad(data->player.angle)));
	

// }

// void	check_wall_part_tow(t_cub3d *data, int *x, int *y)
// {
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
// 	{
// 		*x = data->map.px + (cos(to_rad(data->player.angle)) * MOVE_STEP_V);
// 		*y = data->map.py + (sin(to_rad(data->player.angle)) * MOVE_STEP_V);
// 	}
// 	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
// 	{
// 		*x = data->map.px - (cos(to_rad(data->player.angle)) * MOVE_STEP_V);
// 		*y = data->map.py - (sin(to_rad(data->player.angle)) * MOVE_STEP_V);
// 	}
// }

// int	check_wall(t_cub3d *data)
// {
// 	int	x;
// 	int	y;

// 	printf("check_wall\n");
// 	check_wall_part_tow(data, &x, &y);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_D)
// 		&& !mlx_is_key_down(data->mlx, MLX_KEY_W)
// 		&& !mlx_is_key_down(data->mlx, MLX_KEY_S))
// 	{
// 		x = data->map.px - cos(to_rad(90 - data->player.angle)) * MOVE_STEP_V;
// 		y = data->map.py + sin(to_rad(90 - data->player.angle)) * MOVE_STEP_V;
// 	}
// 	else if (mlx_is_key_down(data->mlx, MLX_KEY_A)
// 		&& !mlx_is_key_down(data->mlx, MLX_KEY_W)
// 		&& !mlx_is_key_down(data->mlx, MLX_KEY_S))
// 	{
// 		x = data->map.px + cos(to_rad(90 - data->player.angle)) * MOVE_STEP_V;
// 		y = data->map.py - sin(to_rad(90 - data->player.angle)) * MOVE_STEP_V;
// 	}
// 	if (data->map.map[(int)(y / data->map.size_shape)]
// 		[(int)(x / data->map.size_shape)] == '1'
// 		|| (data->map.map[(int)(y / data->map.size_shape)][(int)(data->map.px
// 				/ data->map.size_shape)] == '1' && data->map.map[(int)(data->map.py
// 				/ data->map.size_shape)][(int)(x / data->map.size_shape)] == '1'))
// 		return (0);
// 	return (1);
// }
void controle_player(t_cub3d *data) {
    float dir_x = cos(data->player.angle) * MOVE_STEP;
    float dir_y = sin(data->player.angle) * MOVE_STEP;
	float new_x = data->player.pos_x;
    float new_y = data->player.pos_y;
	
    if (mlx_is_key_down(data->mlx, MLX_KEY_W)) {
        new_x += dir_x;
        new_y += dir_y;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_S)) {
        new_x -= dir_x;
        new_y -= dir_y;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_A)) {
        new_x -= dir_y; // 左右移動は角度に垂直
        new_y += dir_x;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_D)) {
        new_x += dir_y;
        new_y -= dir_x;
    }

    if (check_wall(data, new_x, new_y)) {
        data->player.pos_x = new_x;
        data->player.pos_y = new_y;
    }
	printf("data->map.px: %f\n",data->map.px);
	printf("data->map.py: %f\n",data->map.py);
	printf("Old Position: (%f, %f), New Position: (%f, %f)\n", new_x, new_y, data->player.pos_x, data->player.pos_y);
}

int check_wall(t_cub3d *data, float x, float y) {
    int map_x = (int)(x / data->map.size_shape);
    int map_y = (int)(y / data->map.size_shape);
    if (data->map.world_map[map_y][map_x] == 1) {
        return 0; // Wall present
    }
    return 1; // No wall
}
