/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:45:58 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/11 01:35:30 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_player *player, t_cub3d *data)
{
    float angle;
	printf("init_player\n");
    angle = to_rad(player->angle);
	printf("data->map.px: %f\n", data->map.px);
	printf("player->pos_x: %f\n", player->pos_x);
	printf("player->pos_y: %f\n", player->pos_y);
    printf("player->dir_x: %f\n", player->dir_x);
    printf("player->dir_y: %f\n", player->dir_y);
    printf("player->angle: %f\n", player->angle);
    printf("angle: %f\n", angle);
    player->dir_x = cos(data->player.angle * M_PI / 180.0);
    player->dir_y = sin(data->player.angle * M_PI / 180.0);
	player->plane_x = 0;
	player->plane_y = 0.66;
	data->player = *player;
}

void init_ray(t_cub3d *data, t_ray *ray, int x)
{
    ft_memset(ray, 0, sizeof(t_ray));
    ray->ray_pos = 2 * x / (double)WIDTH_WIN - 1;
    ray->ray_dir_x = data->player.dir_x + data->player.plane_x * ray->ray_pos;
    ray->ray_dir_y = data->player.dir_y + data->player.plane_y * ray->ray_pos;
    ray->map_x = (int)data->player.pos_x;
    ray->map_y = (int)data->player.pos_y;
    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
    ray->hit = 0;
    data->ray = *ray;
}

