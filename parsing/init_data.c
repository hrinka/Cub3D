/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:32:34 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/07 22:24:10 by hrinka           ###   ########.fr       */
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
				break ;
			if (i == 0 || data->map[i + 1] == NULL || j == 0 || data->map[i][j + 1] == '\0')
			{
			if (data->map[i][j] != '1' && data->map[i][j] != ' ' && data->map[i][j] != '\t')
			{
				ft_printf( "Error: Map boundaries must be walls or empty spaces.\n");
					exit(EXIT_FAILURE);
			}
			}
			j++;
		}
		i++;
	}
}

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
	data->player.i = 0;
	data->player.j = 0;
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

void	init_world_map(t_cub3d *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("data->map.height_map = %d\n", data->map.height_map);
	printf("data->map.width_map = %d\n", data->map.width_map);
	data->map.world_map = (int **)malloc(data->map.height_map * sizeof(int *));
	while(i < data->map.height_map)
	{
	    data->map.world_map[i] = (int *)malloc(data->map.width_map * sizeof(int));
	    while (j < data->map.width_map)
		{
			char cell = data->map.map[i][j];
			if (cell == '1')
				data->map.world_map[i][j] = 1;
			else if
			(cell == '0' || cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
			    data->map.world_map[i][j] = 0;
			else
			{
				data->map.world_map[i][j] = -1; // Undefined cells, consider error handling here
				printf("Error: Invalid map cell at [%d][%d]\n", i, j);
	        }
			j++;
		}
		i++;
	}
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
	check_dimensions(&data->map);
	init_world_map(data);
	duplicate_player(data);
	get_player_pos(data);
	check_walls(&data->map);
	check_valid_path(data, data->player.i, data->player.j);
}
