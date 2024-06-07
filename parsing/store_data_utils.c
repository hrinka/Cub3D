/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:10:02 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/06 09:19:16 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*remove_newline(char *str)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	printf("i: %d\n", i);
	trimmed = malloc((sizeof(char) * i) + 1);
	if (!trimmed)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		trimmed[j] = str[j];
		j++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

int	check_which_texture(t_cub3d *data, int i, const char *direction)
{
	if (ft_strnstr(data->file_content[i],
			direction, ft_strlen(data->file_content[i])))
	{
		valid_texture_line(data->file_content[i], direction);
		return (1);
	}
	return (0);
}
