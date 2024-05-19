/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 07:51:35 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/05/20 02:24:20 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
// # include <ctype.h>
// # include <string.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "./Libft/libft.h"
# include "./Libft/get_next_line.h"
# include "./Libft/printf.h"
# include "./minilibx-linux/mlx.h"

#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

typedef struct s_player {
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
} t_player;

typedef struct s_ray {
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
	double delta_dist_y;
    double perp_wall_dist;
    int step_x;
    int step_y;
    int hit;
    int side;
} t_ray;

typedef struct s_game {
    void *mlx;
    void *win;
    int world_map[MAP_WIDTH][MAP_HEIGHT];
} t_game;

void draw_vertical_line(t_game *game, int x, int start, int end, int color);
void calculate_step_and_side_dist(t_player *player, t_ray *ray);
void perform_dda(t_ray *ray, int world_map[MAP_WIDTH][MAP_HEIGHT]);
void calculate_distance(t_player *player, t_ray *ray);
void render_wall(t_game *game, t_ray *ray, int x);
void cast_single_ray(t_game *game, t_player *player, int x);
void raycasting(t_game *game, t_player *player);
t_player init_player(void);

#endif