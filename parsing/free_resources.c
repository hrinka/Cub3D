/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:16:14 by hrinka            #+#    #+#             */
/*   Updated: 2024/05/31 20:21:53 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_2dchar_array(char **arr)
{
	char	**temp;
	int		i;

	temp = arr;
	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(arr);
}

void	free_images(t_cub3d *data)
{
	mlx_delete_image(data->mlx, data->textures.no_texture);
	mlx_delete_image(data->mlx, data->textures.so_texture);
	mlx_delete_image(data->mlx, data->textures.ea_texture);
	mlx_delete_image(data->mlx, data->textures.we_texture);
}

void	free_cub_data(t_cub3d *data)
{
	free_2dchar_array(data->file_content);
	free_2dchar_array(data->map.map);
	free_2dchar_array (data->map.tmp);
	free(data->map.map);
	free(data->map.tmp);
	free_images(data);
}

void	close_callback(void *param)
{
	if (param)
		exit(0);
	exit(0);
}
