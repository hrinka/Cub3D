/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:32:34 by hrinka            #+#    #+#             */
/*   Updated: 2024/05/29 12:26:56 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_walls(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '\n')
				break; // 改行文字に達したらその行の処理を終了
			// 最初の行と最後の行のすべての文字、または各行の最初と最後の文字が壁であるかチェック
			if (i == 0 || data->map[i + 1] == NULL || j == 0 || data->map[i][j + 1] == '\0')
			{
				if (data->map[i][j] != '1' && data->map[i][j] != ' ' && data->map[i][j] != '\t')
				{
					fprintf(stderr, "Error: Map boundaries must be walls or empty spaces.\n");
					exit(EXIT_FAILURE);
				}
			}
			j++;
		}
        i++;
	}
}

void	init_struct(t_cub3d *game_data)
{
	game_data->map.file_content = NULL;
	game_data->map.paths.no_path = NULL;
	game_data->map.paths.so_path = NULL;
	game_data->map.paths.we_path = NULL;
	game_data->map.paths.ea_path = NULL;
	game_data->map.map = NULL;
	game_data->textures.sky_hex = -1;
	game_data->textures.floor_hex = -1;
	game_data->player.direction = 0;
	game_data->player.i = 0;
	game_data->player.j = 0;
}

int	check_path_rgb(t_cub3d *data)
{
	if (data->map.paths.no_path == NULL)
		return (1);
	if (data->map.paths.so_path == NULL)
		return (1);
	if (data->map.paths.we_path == NULL)
		return (1);
	if (data->map.paths.ea_path == NULL)
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
		printf("Please enter a map folder with the correct extension (\".cub\")");
		exit(1);
	}
	get_file_content(path_file, data);
	parse_file_content(data);
	duplicate_player(data);
	get_player_pos(data);
	check_dimensions(data);
	check_walls(data);
	check_valid_path(data, data->player.i, data->player.j);
}
