/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:00:07 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/05/20 02:24:22 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_vertical_line(t_game *game, int x, int start, int end, int color) {
    int y;

    y = start;
    while (y < end) {
        mlx_pixel_put(game->mlx, game->win, x, y, color);
        y++;
    }
}

void calculate_step_and_side_dist(t_player *player, t_ray *ray) {
    if (ray->ray_dir_x < 0) {
        ray->step_x = -1;
        ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
    } else {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0) {
        ray->step_y = -1;
        ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
    } else {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
    }
}

void perform_dda(t_ray *ray, int world_map[MAP_WIDTH][MAP_HEIGHT]) {
    while (ray->hit == 0) {
        if (ray->side_dist_x < ray->side_dist_y) {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        } else {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (world_map[ray->map_x][ray->map_y] > 0)
            ray->hit = 1;
    }
}

void calculate_distance(t_player *player, t_ray *ray) {
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->perp_wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void render_wall(t_game *game, t_ray *ray, int x) {
    int line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
    int draw_start = -line_height / 2 + WIN_HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;
    int draw_end = line_height / 2 + WIN_HEIGHT / 2;
    if (draw_end >= WIN_HEIGHT)
        draw_end = WIN_HEIGHT - 1;
    int color = (ray->side == 1) ? 0xAAAAAA : 0xFFFFFF;
    draw_vertical_line(game, x, draw_start, draw_end, color);
}

void cast_single_ray(t_game *game, t_player *player, int x) {
    t_ray ray;

    ray.camera_x = 2 * x / (double)WIN_WIDTH - 1;
    ray.ray_dir_x = player->dir_x + player->plane_x * ray.camera_x;
    ray.ray_dir_y = player->dir_y + player->plane_x * ray.camera_x;
    ray.map_x = (int)player->pos_x;
    ray.map_y = (int)player->pos_y;
    ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
    ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
    ray.hit = 0;

    calculate_step_and_side_dist(player, &ray);
    perform_dda(&ray, game->world_map);
    calculate_distance(player, &ray);
    render_wall(game, &ray, x);
}

void raycasting(t_game *game, t_player *player) {
    int x = 0;
    while (x < WIN_WIDTH) {
        cast_single_ray(game, player, x);
        x++;
    }
}
