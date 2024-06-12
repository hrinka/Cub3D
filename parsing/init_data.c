/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:32:34 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/12 23:41:39 by hrinka           ###   ########.fr       */
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
	// data->player.i = 0;
	// data->player.j = 0;
}

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

void init_world_map(t_cub3d *data) {
    int i, j;

    data->map.world_map = (int **)malloc(data->map.height_map * sizeof(int *));
    if (!data->map.world_map) {
        fprintf(stderr, "Error: Unable to allocate memory for world_map\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < data->map.height_map; i++) {
        data->map.world_map[i] = (int *)malloc(data->map.width_map * sizeof(int));
        if (!data->map.world_map[i]) {
            fprintf(stderr, "Error: Unable to allocate memory for world_map[%d]\n", i);
            // Free previously allocated rows
            while (--i >= 0) {
                free(data->map.world_map[i]);
            }
            free(data->map.world_map);
            exit(EXIT_FAILURE);
        }

        for (j = 0; j < data->map.width_map; j++) {
            char cell = data->map.map[i][j];
            if (cell == '1') {
                data->map.world_map[i][j] = 1;
            } else if (cell == '0' || cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W' || cell == ' ') {
                data->map.world_map[i][j] = 0;
            } else {
                data->map.world_map[i][j] = 1;
                fprintf(stderr, "Error: Invalid map cell at [%d][%d]: '%c'\n", i, j, cell);
            }
        }
    }
}

// void	print_map(t_cub3d *data, char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	(void)map;
// 	printf("print_map\n");
// 	while (j < data->map.height_map)
// 	{
// 		i = 0;
// 		while (i < data->map.width_map)
// 		{
// 			printf("%d", data->map.map[j][i]);
// 			i++;
// 		}
// 		printf("\n");
// 		j++;
// 	}
// }

void	init_game(char *path_file, t_cub3d *data)
{
	init_struct(data);
	if (check_extension(path_file, ".cub") == 1)
	{
		printf("Please enter a map folder with (\".cub\")");
		exit(1);
	}

	printf("START: init_game\n");
	get_file_content(path_file, data);
	parse_file_content(data);
	printf("Map after parsing:\n");
	print_map(data->map.map);//map表示
	duplicate_player(data);
	check_dimensions(&data->map);
	get_player_pos(data);
	init_world_map(data);
	check_walls(&data->map);
	check_valid_path(data, data->player.i, data->player.j);
}
