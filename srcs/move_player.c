/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:17:09 by ahajji            #+#    #+#             */
/*   Updated: 2024/06/08 16:46:13 by hrinka           ###   ########.fr       */
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

void	controle_player(t_cub3d *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) && check_wall(data))
	{
		printf("W\n");
		data->map.px = data->map.px + (cos(to_rad(data->player.angle)) * MOVE_STEP);
		data->map.py = data->map.py + (sin(to_rad(data->player.angle)) * MOVE_STEP);
		printf("check_wall: %d\n", check_wall(data));
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S) && check_wall(data))
	{
		data->map.px = data->map.px - (cos(to_rad(data->player.angle)) * MOVE_STEP);
		data->map.py = data->map.py - (sin(to_rad(data->player.angle)) * MOVE_STEP);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D) && check_wall(data))
	{
		data->map.px = data->map.px - cos(to_rad(90) - to_rad(data->player.angle)) * MOVE_STEP;
		data->map.py = data->map.py + sin(to_rad(90) - to_rad(data->player.angle)) * MOVE_STEP;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A) && check_wall(data))
	{
		data->map.px = data->map.px + cos(to_rad(90) - to_rad(data->player.angle)) * MOVE_STEP;
		data->map.py = data->map.py - sin(to_rad(90) - to_rad(data->player.angle)) * MOVE_STEP;
	}
	printf("data->map.px: %f\n",data->map.px);
	printf("data->map.py: %f\n",data->map.py);
	printf("cos(to_rad(data->player.angle)): %f\n", cos(to_rad(data->player.angle)));
	printf("sin(to_rad(data->player.angle)): %f\n", sin(to_rad(data->player.angle)));
	

}

void	check_wall_part_tow(t_cub3d *data, int *x, int *y)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		*x = data->map.px + (cos(to_rad(data->player.angle)) * MOVE_STEP_V);
		*y = data->map.py + (sin(to_rad(data->player.angle)) * MOVE_STEP_V);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		*x = data->map.px - (cos(to_rad(data->player.angle)) * MOVE_STEP_V);
		*y = data->map.py - (sin(to_rad(data->player.angle)) * MOVE_STEP_V);
	}
}

int	check_wall(t_cub3d *data)
{
	int	x;
	int	y;

	printf("check_wall\n");
	check_wall_part_tow(data, &x, &y);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)
		&& !mlx_is_key_down(data->mlx, MLX_KEY_W)
		&& !mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		x = data->map.px - cos(to_rad(90) - to_rad(data->player.angle)) * MOVE_STEP_V;
		y = data->map.py + sin(to_rad(90) - to_rad(data->player.angle)) * MOVE_STEP_V;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		&& !mlx_is_key_down(data->mlx, MLX_KEY_W)
		&& !mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		x = data->map.px + cos(to_rad(90) - to_rad(data->player.angle)) * MOVE_STEP_V;
		y = data->map.py - sin(to_rad(90) - to_rad(data->player.angle)) * MOVE_STEP_V;
	}
	if (data->map.map[(int)(y / data->map.size_shape)]
		[(int)(x / data->map.size_shape)] == '1'
		|| (data->map.map[(int)(y / data->map.size_shape)][(int)(data->map.px
				/ data->map.size_shape)] == '1' && data->map.map[(int)(data->map.py
				/ data->map.size_shape)][(int)(x / data->map.size_shape)] == '1'))
		return (0);
	return (1);
}
