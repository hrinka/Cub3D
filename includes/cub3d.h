/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:10:16 by hrinka            #+#    #+#             */
/*   Updated: 2024/05/15 13:55:23 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"

# define IMG_PLAYER_R	"./assets/img/player32_r.xpm"
# define IMG_PLAYER_L	"./assets/img/player32_l.xpm"
# define IMG_WALL		"./assets/img/wall.xpm"
# define IMG_EMPTY		"./assets/img/field.xpm"

# define EVENT_KEY_PRESS	2
# define EVENT_DESTROY		33


# define KEY_ESC	0xff1b
# define KEY_LEFT	0xff51
# define KEY_RIGHT	0xff53

# define CHR_WALL	'1'
# define CHR_EMPTY	'0'
# define CHR_PLAYER	'P'

# define PASS		1
# define FAIL		0
# define FINISH		2

# define MAP_MIN	2
# define MAP_MAX	66

# define IMAGE_SIZE 64

# define SPACES		"\t\n\v\f\r "
# define FILE_EXTENSION	".cub"


#endif
