/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:45:49 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/07 23:50:06 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_extension(char *file, char *extension)
{
	char	*file_extension;

	file_extension = ft_strchr(file, '.');
	if (file_extension != NULL && ft_strncmp(file_extension, "./maps", 6) == 0)
	{
		file_extension++;
		file_extension = ft_strchr(file_extension, '.');
	}
	if (file_extension != NULL)
	{
		if (ft_strncmp(file_extension, extension, ft_strlen(extension)
				+ 1) == 0)
			return (0);
		else
			return (1);
	}
	return (1);
}

void	parse_file_content(t_cub3d *data)
{
	int	v;
	int	i;

	i = 0;
	v = 0;
	while (data->file_content[i] != NULL)
	{
		if (empty_line(data->file_content[i]))
			v++;
		if (v == 6)
			break ;
		i++;
	}
	if (store_textures_path(data, ++i) == 0)
	{
		store_map(data, i);
		printf("1\n");
		check_map(&(data->map));
		printf("Map is valid.\n");
	}
	else
	{
		printf("Error, Textures needed weren't provided.\n");
		exit(1);
	}
}
