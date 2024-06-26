/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:42:37 by hrinka            #+#    #+#             */
/*   Updated: 2024/05/31 20:01:45 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	lines_in_file(char *path)
{
	int		fd;
	char	*line;
	int		lines;

	fd = open(path, O_RDONLY);
	lines = 0;
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	get_file_content(char *path, t_cub3d *data)
{
	int	i;
	int	fd;
	int	number_of_lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Unexistant file, please check the path and file name again.\n");
		exit(1);
	}
	i = 0;
	number_of_lines = lines_in_file(path);
	data->file_content = ft_calloc(number_of_lines + 1, sizeof(char *));
	while (1)
	{
		data->file_content[i] = get_next_line(fd);
		if (data->file_content[i] == NULL)
			break ;
		i++;
	}
	data->file_content[i] = NULL;
}
