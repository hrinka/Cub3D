/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:45:06 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/10 19:46:41 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_ray(t_ray ray, t_player *player, int x)
{
	static int	i = 0;

	printf("\n%d\n", i++);
    printf("ray_pos: 2 * %d / %d - 1 = %f\n", x, WIDTH_WIN, ray.ray_pos);
    printf("ray_dir_x: %f + %f * %f = %f\n", player->dir_x, player->plane_x, ray.ray_pos, ray.ray_dir_x);
    printf("ray_dir_y: %f + %f * %f = %f\n", player->dir_y, player->plane_y, ray.ray_pos, ray.ray_dir_y);
    printf("map_x: %d\n", ray.map_x);
    printf("map_y: %d\n", ray.map_y);
    printf("side_dist_x: %f\n", ray.side_dist_x);
    printf("side_dist_y: %f\n", ray.side_dist_y);
    printf("delta_dist_x: 1 / %f = %f\n", ray.ray_dir_x, ray.delta_dist_x);
    printf("delta_dist_y: 1 / %f = %f\n", ray.ray_dir_y, ray.delta_dist_y);
    printf("wall_dist: %f\n", ray.wall_dist);
    printf("step_x: %d\n", ray.step_x);
    printf("step_y: %d\n", ray.step_y);
    printf("hit: %d\n", ray.hit);
    printf("side: %d\n", ray.side);
}

void	print_world_map(t_cub3d *data, int **world_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)world_map;
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