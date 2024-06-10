/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:51:53 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/10 20:03:19 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	duplicate_player(t_cub3d *data)
{
	int	i;
	int	j;
	int	v;

	i = 0;
	v = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
				v++;
			j++;
		}
		i++;
	}
	if (v != 1)
	{
		printf("Please provide a player position in the map (NO DUPLICATES)\n");
		exit(1);
	}
}

void	get_player_pos(t_cub3d *data)
{
	int i = 0;
	while (i < data->map.height_map)
	{
		int j = 0;
		while (j < data->map.width_map)
		{
			if (data->map.world_map[i][j] == 'N' || data->map.world_map[i][j] == 'S' \
			|| data->map.world_map[i][j] == 'E' || data->map.world_map[i][j] == 'W')
			{
                data->player.i = i;
                data->player.j = j;
                data->player.pos_x = j + 0.5;
                data->player.pos_y = i + 0.5;
				// if (c == 'N')
				//     data->player.angle = 270;
				// else if (c == 'S')
				//     data->player.angle = 90;
				// else if (c == 'W')
				//     data->player.angle = 180;
				// else if (c == 'E')
				// 	data->player.angle = 0;
				// return;
			}
            j++;
		}
		i++;
	}
}
