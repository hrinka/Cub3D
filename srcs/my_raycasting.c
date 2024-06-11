/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:00:07 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/11 21:51:45 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_vec(t_player *player, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - player->pos_y) * ray->delta_dist_y;
	}
}


void	dda(t_cub3d *data, int **world_map)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->ray.map_x < 0 || data->ray.map_x >= data->map.width_map || \
			data->ray.map_y < 0 || data->ray.map_y >= data->map.height_map)
			// printf("Ray out of map bounds: map_x=%d, map_y=%d\n", data->ray.map_x, data->ray.map_y);
			data->ray.hit = 1;
            break ;  // Break the loop if out of bounds
		if (world_map[data->ray.map_x][data->ray.map_y] == '1')
		{
			printf("Ray hit wall at: map_x=%d, map_y=%d\n", data->ray.map_x, data->ray.map_y);
			data->ray.hit = 1;
		}
	}
}

void	ray_dist(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x == 0) ray->ray_dir_x = 0.0001;  // 非常に小さい値を0とみなさないようにする
		// printf("ray->map_x(%d) - player->pos_x(%f) + (1 - ray->step_x(%d)) / 2 / ray->ray_dir_x(%f) = %f\n", ray->map_x, player->pos_x, ray->step_x, ray->ray_dir_x, (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x);
		ray->wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	}
	else
	{
		// printf("ray->map_y(%d) - player->pos_y(%f) + (1 - ray->step_y(%d)) / 2 / ray->ray_dir_y(%f) = %f\n", ray->map_y, player->pos_y, ray->step_y, ray->ray_dir_y, (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y);
		if (ray->ray_dir_y == 0) ray->ray_dir_y = 0.0001;  // 非常に小さい値を0とみなさないようにする
		ray->wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	}
    // printf("ray->wall_dist: %f\n", ray->wall_dist);
	if (ray->wall_dist <= 0)
		ray->wall_dist = 0.1;  // 最小値を設定して無限ループや他の数値エラーを防ぐ
}
// void ray_dist(t_player *player, t_ray *ray) {
//     if (ray->side == 0) {
//         ray->wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
//     } else {
//         ray->wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
//     }

//     if (ray->wall_dist <= 0) {
//         ray->wall_dist = 0.1; // 最小値を設定して無限ループや他の数値エラーを防ぐ
//     }
// }

void	single_ray(t_cub3d *data, int x)
{
	t_ray	ray;

	init_ray(data, &ray, x);
	// print_player(player); // debug
	// print_ray(ray, player, x); // debug
	ray_vec(&data->player, &data->ray);
	dda(data, data->map.world_map);
	ray_dist(&data->player, &data->ray);
	render_wall(data, &data->ray, x);
}

void	print_player(t_player *player)
{
	static int	i = 0;

	printf("\n%d\n", i++);
    printf("Player Position: (%f, %f)\n", player->pos_x, player->pos_y);
    printf("Player Angle: %f\n", player->angle);
    // printf("Player Direction: (%f, %f)\n", player->dir_x, player->dir_y);
	// printf("plane_x: %f\n", player->plane_x);
	// printf("plane_y: %f\n", player->plane_y);
}

void	print_world_map(t_cub3d *data, int **world_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)world_map;
	printf("world_map\n");
	while (j < data->map.height_map)
	{
		i = 0;
		while (i < data->map.width_map)
		{
			printf("%d", data->map.world_map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void	raycasting(t_cub3d *data)
{
	int	x;

	x = 0;
	printf("raycasting\n");
	print_player(&data->player);
	init_player(&data->player, data);

	while (x < WIDTH_WIN)
	{
		single_ray(data, x);
		x++;
		if (x == WIDTH_WIN) {
			break;
		}
	}
	print_world_map(data, data->map.world_map);

}
