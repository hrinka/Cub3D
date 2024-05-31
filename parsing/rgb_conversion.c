/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:24:22 by hrinka            #+#    #+#             */
/*   Updated: 2024/05/31 23:32:33 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*skip_to_rgb_values(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'F' && line[i] != 'C' && line[i] != ' '
			&& line[i] != '\t')
			return (&line[i]);
		i++;
	}
	return (NULL);
}

void	validate_rgb_values(char **str)
{
	int	i;
	int	j;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i][0] == '\0')
		{
			printf("Please fix the RGB values, empty string found.\n");
			exit(1);
		}
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != ',')
			{
				printf("Please fix the RGB values, invalid character found.\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	nb_rgb_elem(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

long return_hex_rgb(char *line) {
    char **values;
    long hex_val = -1; // Initialize hex_val to indicate failure by default.
    int r, g, b;

    values = ft_split(line, ',');
    if (!values || nb_rgb_elem(values) != 3) {
        printf("Invalid RGB format.\n");
        free_2dchar_array(values);
        return hex_val; // Return error indicator.
    }

    validate_rgb_values(values); // Assume this function sets up proper error handling or exceptions.
    r = ft_atoi(values[0]);
    g = ft_atoi(values[1]);
    b = ft_atoi(values[2]);
    
    if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) {
        hex_val = ((r << 24) | (g << 16) | (b << 8) | 0xFF); // Include alpha value as 255 (fully opaque)
    } else {
        printf("RGB values must be within the range 0-255.\n");
    }

    free_2dchar_array(values); // Ensure memory is freed in all paths
    return hex_val; // Return the computed value or the error indicator
}


long	rgb_to_hex(char *line)
{
	check_comma(line);
	return (return_hex_rgb(line));
}
