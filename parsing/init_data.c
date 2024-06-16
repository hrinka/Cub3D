/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:32:34 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/16 18:23:58 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_struct(t_cub3d *data)
{
	data->file_content = NULL;
	data->paths.no_path = NULL;
	data->paths.so_path = NULL;
	data->paths.we_path = NULL;
	data->paths.ea_path = NULL;
	data->map.map = NULL;
	data->textures.sky_hex = -1;
	data->textures.floor_hex = -1;
	data->player.direction = 0;
}

// void	check_walls(t_map *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (data->map[i])
// 	{
// 		j = 0;
// 		while (data->map[i][j])
// 		{
// 			if (data->map[i][j] == '\n')
// 				break ;
// 			if (i == 0 || data->map[i + 1] == NULL \
// 				|| j == 0 || data->map[i][j + 1] == '\0')
// 			{
// 				if (data->map[i][j] != '1' && data->map[i][j] != ' ' \
// 					&& data->map[i][j] != '\t')
// 				{
// 					printf("Error: Map boundaries must be walls or empty.\n");
// 					exit(EXIT_FAILURE);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void check_walls(t_cub3d *data)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (data->map.map[i])
// 	{
// 		j = 0;
// 		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
// 		{
// 			if (i == 0 || data->map.map[i + 1] == NULL)  // 上下の境界チェック
// 			{
// 				if (data->map.map[i][j] != '1' && data->map.map[i][j] != ' ')
// 				{
// 					printf("Error: Map boundaries must be walls or empty.\n");
// 					exit(1);
// 				}
// 			}
// 			else if (j == 0 || data->map.map[i][j + 1] == '\n')  // 左右の境界チェック
// 			{
// 				if (data->map.map[i][j] != '1' && data->map.map[i][j] != ' ')
// 				{
// 					printf("Error: Map boundaries must be walls or empty.\n");
// 					exit(1);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
void check_walls(t_map *map_data)
{
	int i;
	int j;

	i = 0;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j] && map_data->map[i][j] != '\n')
		{
			if (i == 0 || map_data->map[i + 1] == NULL)  // 上下の境界チェック
			{
				if (map_data->map[i][j] != '1' && map_data->map[i][j] != ' ')
				{
					printf("Error: Map boundaries must be walls or empty.\n");
					exit(1);
				}
			}
			else if (j == 0 || map_data->map[i][j + 1] == '\n')  // 左右の境界チェック
			{
				if (map_data->map[i][j] != '1' && map_data->map[i][j] != ' ')
				{
					printf("Error: Map boundaries must be walls or empty.\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}


int	check_path_rgb(t_cub3d *data)
{
	if (data->paths.no_path == NULL)
		return (1);
	if (data->paths.so_path == NULL)
		return (1);
	if (data->paths.we_path == NULL)
		return (1);
	if (data->paths.ea_path == NULL)
		return (1);
	if (data->textures.floor_hex == -1)
		return (1);
	if (data->textures.sky_hex == -1)
		return (1);
	return (0);
}

void	init_game(char *path_file, t_cub3d *data)
{
	init_struct(data);
	if (check_extension(path_file, ".cub") == 1)
	{
		printf("Please enter a map folder with (\".cub\")");
		exit(1);
	}
	get_file_content(path_file, data);
	parse_file_content(data);
	sleep(1);
	duplicate_player(data);
	check_dimensions(&data->map);
	get_player_pos(data);
	check_walls(&data->map);
	check_valid_path(data, data->player.i, data->player.j);
}
