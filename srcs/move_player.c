/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:17:09 by ahajji            #+#    #+#             */
/*   Updated: 2024/06/11 14:35:39 by hrinka           ###   ########.fr       */
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

void	check_wall_2(t_cub3d *data, float *new_x, float *new_y)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		*new_x = data->map.px + (cos(to_rad(data->player.angle)) * MOVE_STEP);
		*new_y = data->map.py + (sin(to_rad(data->player.angle)) * MOVE_STEP);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		*new_x = data->map.px - (cos(to_rad(data->player.angle)) * MOVE_STEP);
		*new_y = data->map.py - (sin(to_rad(data->player.angle)) * MOVE_STEP);
	}
}

void    controle_player(t_cub3d *data)
{
    float new_x = data->player.pos_x;
    float new_y = data->player.pos_y;

    check_wall_2(data, &new_x, &new_y);
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
        new_x -= data->player.dir_y * MOVE_STEP;
        new_y += data->player.dir_x * MOVE_STEP;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_D))
    {
        new_x += data->player.dir_y * MOVE_STEP;
        new_y -= data->player.dir_x * MOVE_STEP;
    }

    if (check_wall(data, new_x, new_y))
    {
        printf("Old Position: (%f, %f), New Position: (%f, %f)\n", data->player.pos_x, data->player.pos_y, new_x, new_y);
        data->player.pos_x = new_x;
        data->player.pos_y = new_y;
    }else{
        printf("Hit wall at (%f, %f)\n", new_x, new_y);
    }
}

int check_wall(t_cub3d *data, float x, float y)
{

    check_wall_2(data, &x, &y);
    if (mlx_is_key_down(data->mlx, MLX_KEY_D) && !mlx_is_key_down(data->mlx, MLX_KEY_W) && !mlx_is_key_down(data->mlx, MLX_KEY_S))
    {
        x = data->player.pos_x - cos((data->player.angle + 90) * M_PI / 180.0) * MOVE_STEP;
        y = data->player.pos_y + sin((data->player.angle + 90) * M_PI / 180.0) * MOVE_STEP;
    }
    else if (mlx_is_key_down(data->mlx, MLX_KEY_A) && !mlx_is_key_down(data->mlx, MLX_KEY_W) && !mlx_is_key_down(data->mlx, MLX_KEY_S))
    {
        x = data->player.pos_x + cos((data->player.angle + 90) * M_PI / 180.0) * MOVE_STEP;
        y = data->player.pos_y - sin((data->player.angle + 90) * M_PI / 180.0) * MOVE_STEP;
    }
    if (data->map.map[(int)(y / data->map.size_shape)][(int)(x / data->map.size_shape)] == '1' || 
        (data->map.map[(int)(y / data->map.size_shape)][(int)(data->player.pos_x / data->map.size_shape)] == '1' && 
         data->map.map[(int)(data->player.pos_y / data->map.size_shape)][(int)(x / data->map.size_shape)] == '1'))
        return (0);
    return (1);
}
