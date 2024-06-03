/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:10:48 by hrinka            #+#    #+#             */
/*   Updated: 2024/05/29 19:10:54 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint32_t	get_texel(mlx_image_t *img, int x, int y)
{
	uint8_t	*pixel;
	uint8_t	alpha;
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	pixel = &img->pixels[((y * img->width) + x) * 4];
	red = pixel[0];
	green = pixel[1];
	blue = pixel[2];
	alpha = pixel[3];
	return (red << 24 | green << 16 | blue << 8 | alpha);
}
