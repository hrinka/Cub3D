/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:08:41 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/06 09:20:02 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	store_texture(t_cub3d *data, int i)
{
	const char	*textures[] = {"NO", "SO", "EA", "WE"};
	char		**paths[4];
	int			j;

	paths[1] = &data->paths.so_path;
	paths[2] = &data->paths.ea_path;
	paths[3] = &data->paths.we_path;
	paths[0] = &data->paths.no_path;
	j = 0;
	while (j < 4)
	{
		if (check_which_texture(data, i, textures[j]))
		{
			*paths[j] = remove_newline(ft_strnstr(data->file_content[i],
						"textures", ft_strlen(data->file_content[i])));
			return ;
		}
		j++;
	}	
	if (ft_strchr(data->file_content[i], 'F'))
		data->textures.floor_hex
			= rgb_to_hex(skip_to_rgb_values(data->file_content[i]));
	else if (ft_strchr(data->file_content[i], 'C'))
		data->textures.sky_hex
			= rgb_to_hex(skip_to_rgb_values(data->file_content[i]));
}

int	store_textures_path(t_cub3d *data, int length)
{
	int	i;

	i = 0;
	while (data->file_content[i] != NULL && i < length)
	{
		store_texture(data, i);
		i++;
	}
	if (check_path_rgb(data) == 0)
	{
		printf("Error: Texture path validation failed.\n");
		return (0);
	}
	exit(1);
}

void	init_textures(mlx_t *mlx, t_cub3d *data)
{
	const char		*paths[4] = {data->paths.no_path, data->paths.so_path,
		data->paths.ea_path, data->paths.we_path};
	mlx_image_t		**images[4];
	mlx_texture_t	*loaded_texture;
	int				i;

	images[0] = &data->textures.no_texture;
	images[1] = &data->textures.so_texture;
	images[2] = &data->textures.ea_texture;
	images[3] = &data->textures.we_texture;
	i = 0;
	while (i < 4)
	{
		loaded_texture = mlx_load_png(paths[i]);
		if (!loaded_texture)
		{
			printf("Error: Couldn't initialize the texture for %s\n", paths[i]);
			exit(1);
		}
		*images[i] = mlx_texture_to_image(mlx, loaded_texture);
		mlx_delete_texture(loaded_texture);
		i++;
	}
}

int	map_length(t_cub3d *data, int index)
{
	int	i;

	i = 0;
	while (data->file_content[index] != NULL)
	{
		i++;
		index++;
	}
	return (i);
}

int	store_map(t_cub3d *data, int index)
{
	int	i;
	int	map_length_val;

	i = 0;
	while (data->file_content[index] != NULL
		&& (empty_line(data->file_content[index]) == 0))
		index++;
	map_length_val = map_length(data, index);
	printf("map_length_val: %d\n", map_length_val);
	data->map.map = malloc((map_length_val + 1) * sizeof(char *));
	data->map.tmp = malloc((map_length_val + 1) * sizeof(char *));
	while (data->file_content[index] != NULL)
	{
		data->map.map[i] = ft_strdup(data->file_content[index]);
		data->map.tmp[i] = ft_strdup(data->file_content[index]);
		i++;
		index++;
	}
	data->map.map[i] = NULL;
	data->map.tmp[i] = NULL;
	return (0);
}
